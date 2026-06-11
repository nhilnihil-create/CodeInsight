#include<iostream>
using namespace std;

int main()
{
	int Dice[6];
	int q;
	int up;
	int forward;
	int tmp;
	int i, j, k;
	
	for(i=0;i<6;i++){
		cin >> Dice[i];
	}
	cin >> q;
	
	for(i=0;i<q;i++){
		cin >> up >> forward;
		
		for(j=0;j<4;j++){
			tmp=Dice[0];
			Dice[0]=Dice[1];
			Dice[1]=Dice[5];
			Dice[5]=Dice[4];
			Dice[4]=tmp;
			if(Dice[1]==forward)
					break;

			else{
				for(k=0;k<4;k++){
					tmp=Dice[0];
					Dice[0]=Dice[3];
					Dice[3]=Dice[5];
					Dice[5]=Dice[2];
					Dice[2]=tmp;
					if(Dice[0]==forward){
						tmp=Dice[0];
						Dice[0]=Dice[4];
						Dice[4]=Dice[5];
						Dice[5]=Dice[1];
						Dice[1]=tmp;
						break;
					}
				}
			}
		}
		for(j=0;j<4;j++){
			tmp=Dice[0];
			Dice[0]=Dice[3];
			Dice[3]=Dice[5];
			Dice[5]=Dice[2];
			Dice[2]=tmp;
			if(Dice[0]==up)
				break;
		}
		
		cout << Dice[2] << endl;
	}
	return 0;
}