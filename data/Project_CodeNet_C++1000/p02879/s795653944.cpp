#include <iostream>
#include <stdio.h>
using namespace std;

int A,B;
int main (){
	cin >> A >> B;
	cout << ((A/10+B/10) ? -1: A*B)<< endl;
	return 0; 
}