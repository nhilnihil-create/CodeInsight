//============================================================================
// Name        : 0000.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			int y= i*j;
			cout <<i<<"x"<<j<<"="<<y<<endl;
		}
	}
	return 0;
}