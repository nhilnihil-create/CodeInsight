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
    vector<ll> a(n+1);
    for(i = 0;i <= n;++i){
        cin >> a.at(i);
    }
    vector<ll> limi2(n+1,1);
    for(i = 1;i <= n;++i){
        if(limi2.at(i-1) <= 1e18) limi2.at(i) = limi2.at(i-1)*2ll;
        else limi2.at(i) = limi2.at(i-1);
    }

    vector<ll> uekara(n+1);
    for(i = 0;i <= n;++i){
        if(i == 0){
            if(n == 0){
                if(a.at(i) <= 1) cout << 1 << endl;
                else cout << -1 << endl;
                return 0;
            }
            if(a.at(i) > 0){
                cout << -1 << endl;
                return 0;
            }
            uekara.at(i) = limi2.at(i) - a.at(i);
        }else{
            if(a.at(i) > 2*uekara.at(i-1)){
                cout << -1 << endl;
                return 0;
            }
            uekara.at(i) = min(limi2.at(i), 2*uekara.at(i-1) - a.at(i));
        }
    }

    ll ans = 0;
    ll tmp = 0;
    for(i = n;i >= 1;--i){
        ans += a.at(i);
        tmp += a.at(i);
        if(tmp > uekara.at(i-1)) tmp = uekara.at(i-1);
        ans += tmp;
    }
    cout << ans << endl;

    return 0;
}