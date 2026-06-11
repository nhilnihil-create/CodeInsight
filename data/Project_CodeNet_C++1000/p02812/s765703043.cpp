#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
string S;
int main(){
	cin >> N >> S;
	long long ans = 0;
	rep(i, N - 2) {
		if(S.substr(i, 3) == "ABC") {
			ans++;
		}
	}
	cout << ans << endl;

}