//============================================================================
// Name        : 0521.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int x;
	int ans;

	while(1){

		cin >>x;
		x=(1000-x);

		ans=x/500;
		x=x%500;
		ans=ans+x/100;
		x=x%100;
		ans=ans+x/50;
		x=x%50;
		ans=ans+x/10;
		x=x%10;
		ans=ans+x/5;
		x=x%5;
		ans=ans+x/1;

		cout <<ans<<endl;
		if(x==0){
			break;
		}

	}

	return 0;
}