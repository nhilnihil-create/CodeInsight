#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, a, b, c; 
	cin >> N;
	a = N % 10;
	N /= 10;
	b = N % 10;
	N /= 10;
	c = N % 10;
	if(1000 - (100*c+10*b+a) == 1000){
		cout << 0;
	}
	else{
		cout << 1000 - (100*c+10*b+a);
	}
}

