#include<iostream>
using namespace std;

int main(){
	int tramp[4][13];
	int i,j;
	for (i=0; i<4; i++){
		for (j=0; j<13; j++){
			tramp[i][j] =j+1;
		}
	}
	
	int n;
	cin >>n;
	
	char x;
	int y;
	for (int k=0; k<n; k++){
		cin >>x >>y ;
		for (j=0; j<13; j++){
			if (x=='S' && y==j+1) tramp[0][j] =0;
			if (x=='H' && y==j+1) tramp[1][j] =0;
			if (x=='C' && y==j+1) tramp[2][j] =0;
			if (x=='D' && y==j+1) tramp[3][j] =0;
		}
	}
	
	for (i=0; i<4; i++){
		for (j=0; j<13; j++){
			if (tramp[i][j]==0) continue;
			if (i==0) cout << "S" <<" "<< j+1 <<"\n";
			if (i==1) cout << "H" <<" "<< j+1 <<"\n";
			if (i==2) cout << "C" <<" "<< j+1 <<"\n";
			if (i==3) cout << "D" <<" "<< j+1 <<"\n";
		}
	}	
	
	return 0;
}