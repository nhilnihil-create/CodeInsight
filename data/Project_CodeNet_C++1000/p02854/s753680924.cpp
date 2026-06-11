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
    vector<ll> a(n);
    ll sum = 0;
    for(i = 0;i < n;++i){
        cin >> a.at(i);
        sum += a.at(i);
    }
    ll ans = sum;
    ll tmp = 0;
    for(i = 0;i < n;++i){
        tmp += a.at(i);
        ll t = sum - tmp;
        ans = min(ans, abs(tmp - t));
    }
    cout << ans << endl;
    


    return 0;
}