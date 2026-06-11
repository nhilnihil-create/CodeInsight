#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<int> Dice;

/*
Top  [0]
Front[1]
Right[2]
Left [3]
Back [4]
Bottom[5]
*/
void roll_n(Dice &dice)
{
	int a = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = a;
}
void roll_e(Dice &dice)
{
	int a = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = a;
}
void roll_w(Dice &dice)
{
	int a = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = a;
}
void roll_s(Dice &dice)
{
	int a = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = a;
}
void roll(Dice &dice, char direction)
{
	if(direction == 'N'){
		roll_n(dice);
	}
	else if(direction == 'E'){
		roll_e(dice);
	}
	else if(direction == 'W'){
		roll_w(dice);
	}
	else{
		roll_s(dice);
	}
}
int main(void)
{	
	Dice dice(6);
	
	for(int i = 0; i < dice.size(); i++){
		cin >> dice[i];
	}
	
	string directions;
	cin >> directions;
	
	for(int i = 0; i < directions.size(); i++){
		roll(dice, directions[i]);
	}
	
	cout << dice[0] << endl;

	return 0;
}