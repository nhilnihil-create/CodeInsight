#include <bits/stdc++.h>
#include<string>
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define len(s) s.length()
#define all(v) v.begin(),v.end()
const ll INF = LONG_MAX;
// const int N = 2e5 + 5;
const ll mod = 1000000007 ;
using namespace std;



ll A, B, N;

ll check(ll mid) {
	ll cur = (A * mid) / B - A * (mid / B);
	return cur;
}

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	ll tc = 1;
	// cin >> tc;

	while (tc--) {

		ll n, m, k, i, j;
		ll x, y;


		cin >> A >> B >> N;

		ll l = 1, r = N;

		ll mid;
		ll cur = 0;

		while (l <= r) {
			mid = l + (r - l) / 2;

			ll cmp = check(mid);
			// cout << mid << endl;
			// cout << cmp << endl;

			if (cmp >= cur) {
				cur = max(cur, cmp);
				l = mid + 1;
			}
			else
				r = mid - 1;
		}

		cout << cur << endl;

	}

}