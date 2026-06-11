#include <stdio.h>
#include <iostream>
using namespace std;

int N,R, inner;
int main(){
	cin >> N >> R;
	if (N<10){
		inner = R+ 100*(10-N);	
		cout << inner;
	}else {
		cout << R;
	}
}
