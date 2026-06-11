#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    sort(all(a), greater<ll>());
    ll sup = n;
    ll inf = 0;
    ll meyasu = a.at(p-1);
    while(sup - inf > 1){
        ll mid = (sup + inf)/2;
        if(meyasu - a.at(mid) > m){
            sup = mid;
            continue;
        }
        ll tmp = m*(p-1) + m*(n - mid);
        for(i = p-1;i < mid;++i){
            tmp += a.at(mid) + m - a.at(i);
        }
        if(tmp < m*v) sup = mid;
        else inf = mid;
    }
    cout << sup << endl;
    return 0;
}