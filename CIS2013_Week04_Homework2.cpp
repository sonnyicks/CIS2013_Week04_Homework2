#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int card = 0;
int dealer_total = 0;
int player_total = 0;

char pdraw (int);
char ddraw (int);
int reset ();

bool player_stay = false;
bool player_done = false;
bool dealer_done = false;
bool play_again = true;
char yes_or_no = 'n';
char hit_stay = 'h';

int main(){
	srand(time(0));
	while (play_again){
	pdraw (card);
	pdraw (card);
	ddraw (card);
	cout << endl << "Your total = " << player_total << endl;
	while ((player_done==false) && (dealer_done==false)){
	cout << "Hit or Stay (H/S)?: ";
	cin >> hit_stay;
	if (((hit_stay=='h')||(hit_stay=='H'))&& (player_done==false)){
		pdraw (card);
		if (player_total==21){
		cout << "21, you win!" << endl;
		player_done=true;
		dealer_done=true;}
			else if (player_total < 21){
				cout << endl << "Your total = " << player_total << endl;
			}
			else{
				cout << player_total << ", you bust." << endl;
				player_done=true;
			}
		}
	//Dealer's turn
	else if (dealer_done==false){
		cout << "You stay with " << player_total << endl << endl;
		ddraw (card);
		cout << "Dealer total = " << dealer_total << endl;
		while (dealer_total < 17){
			ddraw (card);
			cout << "Dealer total = " << dealer_total << endl;
		}
		if ((dealer_total>16) && (dealer_total<22)){
			cout << "Dealer stays" << endl;
			dealer_done=true;
		}
		else{
			cout << "Dealer busts.  You win!" << endl;
			dealer_done=true;
		}
	}
	}
	
	
	if ((player_total < 21)&&(dealer_total < 22)){
		cout << endl << "You have " << player_total << endl;
		cout << "Dealer has " << dealer_total << endl;
		if (player_total>=dealer_total){cout << "You win!" << endl;}
		else {cout << "Dealer wins." << endl;}
	}
	cout << "Play again? (Y/N): ";
	cin >> yes_or_no;
	cout << endl;
	if ((yes_or_no=='n')||(yes_or_no=='N')){play_again=false;}
	else{reset();}
	}
	return 0;
}


char pdraw (int card){
	card = (rand() % 13) +1;
	if (card==1){
		cout << "You're dealt an Ace" << endl;
		player_total=player_total+1;
	}
	else if (card<=10){
		cout << "You're dealt a " << card << endl;
		player_total=player_total+card;
	}
	else if (card==11){
		cout << "You're dealt a Jack" << endl;
		player_total=player_total+10;
	}
	else if (card==12){
		cout << "You're dealt a Queen" << endl;
		player_total=player_total+10;
	}
	else if (card==13){
		cout << "You're dealt a King" << endl;
		player_total=player_total+10;
	}
	return 'c';
}
char ddraw (int card){
		card = (rand() % 13) +1;
	if (card==1){
		cout << "Dealer gets an Ace" << endl;
		dealer_total=dealer_total+1;
	}
	else if (card<=10){
		cout << "Dealer gets a " << card << endl;
		dealer_total=dealer_total+card;
	}
	else if (card==11){
		cout << "Dealer gets a Jack" << endl;
		dealer_total=dealer_total+10;
	}
	else if (card==12){
		cout << "Dealer gets a Queen" << endl;
		dealer_total=dealer_total+10;
	}
	else if (card==13){
		cout << "Dealer gets a King" << endl;
		dealer_total=dealer_total+10;
	}
	return 'c';
}
int reset(){
player_stay = false;
player_done = false;
dealer_done = false;
dealer_total = 0;
player_total = 0;
return 0;
}
