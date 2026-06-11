#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    for(i = 0;i < n;++i){
        cin >> f.at(i);
    }
    sort(all(a));
    sort(all(f),greater<ll>());
    ll tmpmax = 0;
    ll tmpsuma = 0;
    for(i = 0;i < n;++i){
        tmpmax = max(tmpmax, a.at(i)*f.at(i));
        tmpsuma += a.at(i);
    }
    if(tmpsuma <= k){
        cout << 0 << endl;
        return 0;
    }
    if(k == 0){
        cout << tmpmax << endl;
        return 0;
    }
    ll sup = tmpmax;
    ll inf = 1;
    while(true){
        if(sup == inf){
            break;
        }
        ll tmp = (sup + inf)/2;
        ll tmpk = 0;
        for(i = 0;i < n;++i){
            tmpk += max(a.at(i) - tmp/f.at(i),0LL);
        }
        if(tmpk <= k){
            sup = tmp;
        }else{
            inf = tmp+1;
        }
    }
    cout << inf << endl;
    return 0;
}