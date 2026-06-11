#include <iostream>
#include <stdio.h>
using namespace std;

int K,X;
int main (){
	cin >> K >> X;
	for(int i=0;i<(2*K-1);i++) {
		cout << X - (K - 1) + i << endl;
	}
	return 0;
}