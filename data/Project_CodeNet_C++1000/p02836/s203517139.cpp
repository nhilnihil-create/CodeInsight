#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

int main(){
	string S;
	cin >> S;
	long long ans = 0;
	rep(i, S.size()/2) {
		if(S[i] != S[S.size() - 1 - i]) {
			ans++;
		}
	}
	cout << ans << endl;
}
