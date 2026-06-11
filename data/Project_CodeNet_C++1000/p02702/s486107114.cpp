#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int m[200010];

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    string s;
    cin >> s;

    map<int, int> mp;
    mp[0]++;
    for (int i = s.size() - 1; i >= 0; --i) {
        m[i] = ((s[i] - '0') * modpow(10, s.size() - 1 - i, 2019) + m[i+1]) % 2019;
        mp[m[i]]++;
    }

    ll res = 0;
    for (auto x : mp){
        res += x.second * (x.second - 1) / 2;
    }
    cout << res << endl;
}