#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

int main(){
	long long A, B;
	cin >> A >> B;
	if(A > 9 || B > 9) {
		cout << -1 << endl;
	} else {
		cout << A * B << endl;
	}
}
