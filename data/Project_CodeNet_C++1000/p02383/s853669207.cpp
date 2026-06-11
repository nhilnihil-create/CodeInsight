#include <iostream>
#include<cmath>
#include<string>
#include <vector>
using namespace std;


int main(){

	int num;
	string direction;
	int Dice[6] = {};//{0,1,2,3,4,5}={???,S,E,W,N,???}
	int Dice_b[6] = {};
	for (int i = 0; i < 6; i++){//???????????????????????°????????£??\
		cin >> num;
		Dice[i] = num;
	}

	cin >> direction;//??????????????£??\

	for (int i = 0; direction[i]; i++){
	
		switch (direction[i]){
		
		case 'S':
			Dice_b[0] = Dice[4];
			Dice_b[1] = Dice[0];
			Dice_b[2] = Dice[2];//E
			Dice_b[3] = Dice[3];//W
			Dice_b[4] = Dice[5];
			Dice_b[5] = Dice[1];
			break;

		case 'E':
			Dice_b[0] = Dice[3];
			Dice_b[1] = Dice[1];//S
			Dice_b[2] = Dice[0];
			Dice_b[3] = Dice[5];
			Dice_b[4] = Dice[4];//N
			Dice_b[5] = Dice[2];
			break;

		case 'W':
			Dice_b[0] = Dice[2];
			Dice_b[1] = Dice[1];//S
			Dice_b[2] = Dice[5];
			Dice_b[3] = Dice[0];
			Dice_b[4] = Dice[4];//N
			Dice_b[5] = Dice[3];
			break;
		case 'N':
			Dice_b[0] = Dice[1];
			Dice_b[1] = Dice[5];
			Dice_b[2] = Dice[2];//E
			Dice_b[3] = Dice[3];//W
			Dice_b[4] = Dice[0];
			Dice_b[5] = Dice[4];
			break;		
		}//switch???

        //Dice_b????????????Dice????????????
		for (int i = 0; i < 6; i++){
			Dice[i] = Dice_b[i];
		}
	}	//??°???????????????

	cout << Dice[0] << endl;


	return 0;
}