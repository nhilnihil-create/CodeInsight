#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,d,a;
    cin >> n >> d >> a;
    vector<pair<ll,ll>> x(n);
    vector<ll> indx(n);
    for(i = 0;i < n;++i){
        cin >> x.at(i).first >> x.at(i).second;
        indx.at(i) = x.at(i).first;
    }
    sort(all(x));
    sort(all(indx));
    vector<ll> imos(n,0);
    ll ans = 0;
    for(i = 0;i < n;++i){
        if(i == 0){
            ll dif = x.at(i).second;
            ll tmp = ((dif-1)/a+1)*a;
            ans += tmp/a;
            imos.at(i) += tmp;
            ll dis = indx.at(i) + 2*d;
            ll ind = upper_bound(all(indx), dis) - indx.begin();
            if(ind == n){
                continue;
            }else{
                imos.at(ind) -= tmp;
            }
        }else{
            imos.at(i) += imos.at(i-1);
            if(imos.at(i) >= x.at(i).second)    continue;
            ll dif = x.at(i).second - imos.at(i);
            ll tmp = ((dif-1)/a+1)*a;
            ans += tmp/a;
            imos.at(i) += tmp;
            ll dis = indx.at(i) + 2*d;
            ll ind = upper_bound(all(indx), dis) - indx.begin();
            if(ind == n){
                continue;
            }else{
                imos.at(ind) -= tmp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}