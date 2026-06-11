#include <bits/stdc++.h>

#define pb push_back
#define PQ priority_queue
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

typedef long long ll;
typedef long double ld;

//__builtin_popcount(x)

using namespace std;

/*const int mod = 1e9 + 7;

ll add(ll a, ll b) {
    ll res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

ll sub(ll a, ll b) {
    ll res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

ll mul(ll a, ll b) {
    return (((a % mod) * (b % mod)) % mod);
}

int powm(int a, long long n) {
	if (n == 0) {
		return 1;
	}
	else if (n & 1) {
		return mul(a, powm(a, n - 1));
	}
	else {
		return powm(mul(a, a), n / 2);
	}
}*/

/* Z-FUNCTION
ll l = 0, r = 0, n = (int)s.size();
vector<int> z(n, 0);
for (int i = 1; i < n; i++) {
    if (r >= i) {
        z[i] = min(1ll*z[i-l], r-i+1);
    }
    while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
}
*/

/*vector<ll> find_dividers(ll x) {
    vector<ll> dividers;

    for (ll i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
           dividers.push_back(i);
            if (1ll*i * i != x) {
                dividers.push_back(1ll*x / 1ll*i);
            }
        }
    }

    return dividers;
}*/

/*int nok(int a, int b) {
    return a / __gcd(a, b) * b;
}*/

// ceil(a/b) = (a+b-1)/b

void solve() {
    int n;
    cin >> n;
    ll total = 0;
    for (int a = 1; a < n; a++) {
        total += (n - 1)/a;
    }
    cout << total << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.setf(ios::fixed);
    //cout.precision(10);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
