#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    ll now = 1;
    ll ans = 0;
    rep(i,n){
        ll a;
        cin >> a;
        if(now == a){
            ++ans;
            ++now;
        }
    }
    if(!ans) cout << -1 << endl;
    else cout << n - ans << endl;

    return 0;
}