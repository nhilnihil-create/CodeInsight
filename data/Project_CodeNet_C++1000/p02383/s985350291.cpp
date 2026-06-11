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
};

int main(){
	Dice dice1;
	string D;
	
	for(int i = 0;i < 6;i++){
		cin >> dice1.face[i];
	}
		cin >> D;
	for(int j = 0;j < D.size();j++){
		dice1.direction(D[j]);
	}
	cout << dice1.face[0] << endl;
	return 0;
}