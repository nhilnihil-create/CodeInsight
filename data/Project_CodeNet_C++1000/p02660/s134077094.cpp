#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

vector<pair<ll ,ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) {
            num++;
            n /= p; 
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main() {

    ll n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<pair<ll, ll>> prime = prime_factorize(n);

    ll cnt = 0;

    for(auto a : prime) {
        ll tmp = a.second;
        ll i = 1;
        while (i <= tmp) {
            tmp -= i;
            i++;
            cnt++;
        }
    }

    cout << cnt << endl;

return 0;
}