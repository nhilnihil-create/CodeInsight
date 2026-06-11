#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define D(x) cerr << #x << " = " << (x) << '\n'
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	set<ll> answer;
	cin >> n;
	for(ll i = 1; i * i <= n - 1; ++ i) {
		if((n - 1) % i == 0) {
			answer.insert(i);
			if(i != (n - 1) / i) answer.insert((n - 1) / i);
		}
	}
	for(ll i = 2; i * i <= n; ++ i) {
		ll x = n;
		while(x % i == 0) x /= i;
		if(x % i == 1) answer.insert(i);
	}
	cout << sz(answer) << '\n';
}
