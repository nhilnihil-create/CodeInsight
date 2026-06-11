//============================================================================
// Name        : AOJ.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,b,f,r,v;
	int A[5][4][11]={};
	cin>>n;

	for (int i=0;i<n;i++){
		cin>>b>>f>>r>>v;
		A[b][f][r]+=v;
	}


	for (int b=1;b<=4;b++){
		if (b>1)cout<<"####################\n";
		for (int f=1;f<=3;f++){
			for (int r=1;r<=10;r++){
				cout<<" "<< A[b][f][r];
			}
			cout<<endl;

		}
	}


	return 0;
}