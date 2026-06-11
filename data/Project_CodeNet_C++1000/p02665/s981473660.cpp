// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    const ll LIM = 1e14;

    ll n; cin >> n;
    ll a[n+1]; rep(i,n+1) cin >> a[i];


    bool flag = true;
    rep(i,n){
        if(a[i+1] != 0){
            flag = false;
            break;
        }
    }
    if(a[0] == 1 && flag){
        cout << 1 << endl;
        return 0;
    }else if(a[0] != 0 && (!flag)){
        cout << -1 << endl;
        return 0;
    }

    ll nleaf = 1LL;
    ll ans = 0LL;
    ll v[n+1];
    rep(i,n){
        if(nleaf <= a[i]){
            cout << -1 << endl;
            return 0;
        }
        nleaf -= a[i];
        v[i] = nleaf;
        nleaf <<= 1LL;
        if(nleaf > LIM) nleaf = LIM;
    }

    if(nleaf < a[n]){
        cout << -1 << endl;
        return 0;
    }

    nleaf = a[n];
    ans += a[n];
    for(ll i = n-1; i >= 0; --i){
        if(v[i]*2 < nleaf){
            cout << -1 << endl;
            return 0;
        }
        if(v[i] > nleaf) v[i] = nleaf;
        nleaf = v[i] + a[i];
        ans += nleaf;
    }
    cout << ans << endl;
}