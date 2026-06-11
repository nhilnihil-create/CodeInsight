#include <stdio.h>
#include <iostream>
using namespace std;

int S,W;
int main (){
	cin >> S >> W;
	if (S<=W){
		cout << "unsafe";
	}else{
		cout << "safe";
	}
}