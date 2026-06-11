#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        ll a,b;
        cin >> a >>b;
        v[i].second = a-b;
        v[i].first  = a+b;
    }
    sort(v.begin(),v.end());
    ll res = 0;
    ll pos = -INF;
    rep(i,n){
        if(pos <= v[i].second){
            res++;
            pos = v[i].first;
        }
    }
    cout << res << "\n";
    return 0;
}