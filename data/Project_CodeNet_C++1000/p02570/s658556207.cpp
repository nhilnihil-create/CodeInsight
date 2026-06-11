#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repp(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define repd(i, n) for(ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()

int k, l, m, n;
const int M = 1e9 + 7;



/* int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, t, s;
    cin >> d >> t >> s;

    if((double)d / s <= (double)t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
} */

int main() {
	int d, t, s;
	cin >> d >> t >> s;

	if((double)d / s <= t) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}