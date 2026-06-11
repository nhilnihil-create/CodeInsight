#include<bits/stdc++.h>
#include<string>
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define S second
#define F first
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	ll ans = 0;
	if (n % 2 == 0) {
		ll st = 10;
		while (st <= n) {
			ans = ans + (n / st);
			st = st * 5;
		}
	}
	else {
		ans = 0;
	}

	cout << ans << '\n';
}