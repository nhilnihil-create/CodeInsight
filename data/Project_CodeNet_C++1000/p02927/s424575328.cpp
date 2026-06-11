#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll m,d;
    cin >> m >> d;
    ll ans = 0;
    for(i = 1;i <= m;++i){
        for(j = 1;j <= d;++j){
            if(j < 10) continue;
            ll t = j/10;
            ll s = j%10;
            if(t < 2) continue;
            if(s < 2) continue;
            if(i == t*s) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}