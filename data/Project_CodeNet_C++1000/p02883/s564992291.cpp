#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll n,k;
vector<ll>a,f;

// index が条件を満たすかどうか
bool isOK(ll c) {
    ll res = 0;
    rep(i,n){
        ll now = c/f[i];
        if(now>=a[i])continue;
        res += a[i]-now;
    }
    if(res<=k)return true;
    else return false;
}
// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = (ll)1e12+5; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> n >> k;
    a.resize(n);
   rep(i,n)cin>>a[i];
   f.resize(n);
   rep(i,n)cin>>f[i];
   sort(a.begin(),a.end());
   sort(f.rbegin(),f.rend());
   ll x = binary_search();
   cout << x << endl;
    return 0;
}
