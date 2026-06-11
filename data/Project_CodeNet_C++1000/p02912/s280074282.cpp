#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, M;

int main(){
	cin >> N >> M;
	priority_queue<ll> A;
	rep(i, N) {
		ll a;
		cin >> a;
		A.push(a);
	}

	while(M) {
		ll a = A.top();
		A.pop();
		A.push(a/2);
		M--;
	}

	ll ans = 0;
	while(!A.empty()) {
		ll a = A.top();
		A.pop();
		ans += a;
	}
	cout << ans << endl;
}
