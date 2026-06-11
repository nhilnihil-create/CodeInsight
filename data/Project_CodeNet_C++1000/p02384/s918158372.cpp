#include <iostream>
#include <string>
using namespace std;

class Dice{
	public:
	int face[6];
	
	Dice(){}
	void direction(char ch){
			if(ch == 'E') rotate(0,2,5,3);
			if(ch == 'W') rotate(0,3,5,2);
			if(ch == 'S') rotate(0,1,5,4);
			if(ch == 'N') rotate(0,4,5,1);
	}

	void rotate(int a,int b,int c,int d){
		int temp[4] = {};

		temp[0] = face[a];
		temp[1] = face[b];
		temp[2] = face[c];
		temp[3] = face[d];
		//ダイス入れ替え
		face[a] = temp[3];
		face[b] = temp[0];
		face[c] = temp[1];
		face[d] = temp[2];

	}
	int sidespin(int f){
		if(f == 0 || f == 1 || f == 5) {return 0;}
		if(f == 3) rotate(1,2,4,3);
		if(f == 2) {
				for(int i = 0;i < 3;i++){
						rotate(1,2,4,3);
				}
		}
		if(f == 4) {
				for(int i = 0;i < 2;i++){
						rotate(1,2,4,3);
				}
		}
	}
};

int main(){
	Dice dice1;
	int n,top,front,t_num = 0,f_num = 0;
	
	for(int i = 0;i < 6;i++){
		cin >> dice1.face[i];
	}
		cin >> n;
	for(int i = 0;i < n;i++){
		cin >> top >> front;
		//上の面まで回転
		
		for(t_num = 0;t_num < 6;t_num++){
			if(dice1.face[t_num] == top) break;
		}
		switch(t_num){
				case 0:break;
				case 1:
					  dice1.direction('N');
					  break;
				case 4:
					  dice1.direction('S');
					  break;
				case 5:
					  dice1.direction('N');
					  dice1.direction('N');
					  break;
				case 2:
					  dice1.direction('W');
					  break;
				case 3:
					  dice1.direction('E');
					  break;
				default: break;
		}
		//前の面まで回転
		for(f_num = 0;f_num < 6;f_num++){
			if(dice1.face[f_num] == front) break;
		}
		dice1.sidespin(f_num);
		cout << dice1.face[2] << endl;
	}
	return 0;
}