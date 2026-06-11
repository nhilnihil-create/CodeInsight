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
    ll sum = 0;
    for(i = 0;i < n;++i){
        cin >> a.at(i);
        sum += a.at(i);
    }
    ll supy = sqrt(sum);
    set<ll> b;
    for(i = 1;i <= supy+1;++i){
        if(sum%i == 0){
            b.insert(i);
            b.insert(sum/i);
        }
    }
    vector<ll> betsu;
    for(auto x:b){
        betsu.push_back(x);
    }
    for(i = betsu.size()-1;i >= 1;--i){
        ll x = betsu.at(i);
        vector<ll> tasu(n);
        vector<ll> lower(n);
        ll tmp = 0;
        rep(j,n){
            if(a.at(j)%x == 0){
                tasu.at(j) = 0;
                lower.at(j) = a.at(j);
                tmp += lower.at(j);
            }else{
                ll spare = a.at(j)%x;
                tasu.at(j) = x - spare;
                lower.at(j) = a.at(j) - spare;
                tmp += lower.at(j);
            }
        }
        ll need = (sum - tmp)/x;
        sort(all(tasu));
        ll nokori = 0;
        ll cnt = 0;
        rep(j,n){
            if(nokori == need) break;
            if(tasu.at(j) == 0) continue;
            else{
                ++nokori;
                cnt += tasu.at(j);
            }
        }
        if(cnt <= k){
            cout << x << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}