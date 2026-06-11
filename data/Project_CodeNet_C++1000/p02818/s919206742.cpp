#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

int main(){
	long long A, B, K;
	cin >> A >> B >> K;

	if(K>= A+B) {
		cout << "0 0"<<endl;
		return 0;
	}
	if(K>=A) {
		cout << 0 << " " << A + B - K << endl;
		return 0;
	}
	cout << A - K << " " << B << endl;


}
