#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    if (p == 2 || p == 5){
        ll res = 0;
        for (int i = n-1; i >= 0; --i){
            if ((s[i] - '0') % p == 0){
                res += i+1;
            }
        }
        cout << res << endl; 
    } else{
        for (int i = n-1; i >= 0; --i){
            m[i] = (((s[i] - '0') % p) * modpow(10, n-1-i, p) + m[i+1]) % p;
        }

        map<int, int> mp;
        for (int i = 0; i <= n; ++i) {
            mp[m[i]]++;
        }
        ll res = 0;
        for (auto &x : mp){
            res += (ll)x.second * (ll)(x.second - 1) / 2;
        }
        cout << res << endl;
    }
}