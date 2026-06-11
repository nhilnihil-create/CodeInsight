#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	string S;
	cin >> S;
	rep(i, S.size()) {
		if(i%2 == 0) {
			if(S[i] != 'R' && S[i] != 'U' && S[i] != 'D') {
				cout << "No" << endl;
				return 0;
			}
		} else {
			if(S[i] != 'L' && S[i] != 'U' && S[i] != 'D') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

}