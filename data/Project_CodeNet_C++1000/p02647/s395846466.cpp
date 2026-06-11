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
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    if(k >= 50){
        for(i = 0;i < n;++i){
            cout << n << endl;
        }
        return 0;
    }else{
        rep(j,k){
            vector<ll> b(n,0);
            for(i = 0;i < n;++i){
                ++b.at(max(0ll, i-a.at(i)));
                if(i + a.at(i) + 1 < n) --b.at(i + a.at(i) + 1);
            }
            for(i = 0;i < n-1;++i){
                b.at(i+1) += b.at(i);
            }
            for(i = 0;i < n;++i){
                a.at(i) = b.at(i);
            }
        }
        for(i = 0;i < n;++i){
            cout << a.at(i) << endl;
        }
    }

    return 0;
}