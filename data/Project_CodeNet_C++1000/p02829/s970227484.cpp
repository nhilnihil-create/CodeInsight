#include <stdio.h>
#include <iostream>
using namespace std;

int A,B;
int main (){
	cin>> A >> B;
	if (A==1){
		if (B==2){
			cout <<"3";
		}else if (B==3){
			cout <<"2";
		}
	}else if (A==2){
		if (B==1){
			cout <<"3";
		}else if (B=3){
			cout <<"1";
		}
	}else if (A==3){
		if (B==1){
			cout <<"2";
		}else if (B==2){
			cout <<"1";
		}
	}
}