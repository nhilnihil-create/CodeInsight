#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>
using namespace std;

class Dice{
public:
	int f[6];

	Dice (){}
	
	void move(char x){
		int c=0;
		if (x=='E'){
			c=f[5], f[5]=f[2], f[2]=f[0], f[0]=f[3], f[3]=c;
		}	
		if (x=='W'){
			c=f[3], f[3]=f[0], f[0]=f[2], f[2]=f[5], f[5]=c;
		}
		if (x=='S'){
			c=f[5], f[5]=f[1], f[1]=f[0], f[0]=f[4], f[4]=c;
		}		
		if (x=='N'){
			c=f[5], f[5]=f[4], f[4]=f[0], f[0]=f[1], f[1]=c;
		}			
	}


};

int main(){
	Dice d;
	
	for (int k=0; k<6; k++){
		cin >> d.f[k];
	}
	
	string DD;
	cin >> DD;
	
	for (int n=0; n<DD.size(); n++){
		d.move(DD[n]);
	}
	
	cout << d.f[0] << endl;
	
	return 0;
}