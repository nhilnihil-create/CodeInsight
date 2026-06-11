#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;

int main(){
	cin >> N;

	ll ans = 0;
	ll tmpans = 0;
	ll cur = -1;
	rep(i, N) {
		ll tmp;
		cin >> tmp;

		if(cur >= tmp) {
			tmpans++;
		} else {
			ans = max(ans, tmpans);
			tmpans = 0;
		}
		cur = tmp;
	}
	ans = max(ans, tmpans);
	cout <<  ans << endl;
}