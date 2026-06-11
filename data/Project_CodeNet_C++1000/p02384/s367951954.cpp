// last edited at 23/8/2015 by charis

#include<iostream>
using namespace std;

class Dice{
public:
	int f[6];
	Dice(){}
	
	int aa(int i, int j, int x, int y, int z, int w){
		return (i==x && j==y) || (i==y && j==z) || (i==z && j==w) || (i==w && j==x);
	}
	void right(int i, int j){
		if( aa(i, j, 0, 1, 5, 4) ) cout << f[2] << endl;
		else if( aa(i, j, 4, 5, 1, 0) ) cout << f[3] << endl;			
		else if( aa(i, j, 0, 3, 5, 2) ) cout << f[1] << endl;
		else if( aa(i, j, 2, 5, 3, 0) ) cout << f[4] << endl;
		else if( aa(i, j, 1, 2, 4, 3) ) cout << f[0] << endl;
		else if( aa(i, j, 3, 4, 2, 1) ) cout << f[5] << endl;
		} 
	int c(int a, int b){
		for (int i=0; i<6; i++){
			for (int j=0; j<6; j++){
				if (f[i]==a && f[j]==b) right(i, j);			
			}
		}
	}
};

int main(){
	
	Dice d;
	int q;
	for (int n=0; n<6; n++){
		cin >> d.f[n] ;
	}
	
	cin >> q ;
	int a, b;
	for (int m=0; m<q; m++){
		cin >> a >> b ;
		d.c(a, b);
	}
	
	return 0;
}