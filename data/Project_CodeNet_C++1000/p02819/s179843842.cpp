#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

bool prime(int x){
	int i = 2;
	while (i*i<=x){
		if (x%i == 0){
			return false;
		}
		i++;
	}
	return true;
}

int main(void){
	int X;
	cin >> X;
	
	while (X){
		if (prime(X)) {
			cout << X << endl;
			return 0;
		}
		X++;
	}


	return 0;
}
