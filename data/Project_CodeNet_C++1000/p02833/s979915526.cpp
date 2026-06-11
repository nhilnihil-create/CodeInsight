#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;

    if(N%2) {
        cout << 0 << endl;
        return 0;
    }

    ll k = N / 2;
    ll c2 = k, c5 = 0;
    
    ll p = 2;
    while(k / p > 0) {
        c2 += k / p;
        p *= 2;
    }
    p = 5;
    while(k / p > 0) {
        c5 += k / p;
        p *= 5;
    }
    cout << min(c2, c5) << endl;
}
