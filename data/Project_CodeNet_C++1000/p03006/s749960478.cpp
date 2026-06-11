#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    pair<ll, ll> x[n];
    rep(i, 0, n){
        cin >> x[i].first >> x[i].second;
    }

    sort(x, x + n);

    ll num = 0;
    rep(i, 0, n - 1){
        pair<ll, ll> dif;
        dif.first = x[i+1].first - x[i].first;
        dif.second = x[i+1].second - x[i].second;
        ll count = 0;
        rep(j, 0, n - 1){
            if(x[j+1].first - x[j].first == dif.first && x[j+1].second - x[j].second == dif.second){
                count++;
            }
        }
        num = max(num, count);
    }

    ll ma = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            if(x[i].first - x[j].first == 0 && x[i].second - x[j].second == 0) continue;
            pair<ll, ll> dif;
            dif.first = x[i].first - x[j].first;
            dif.second = x[i].second - x[j].second;

            ll count = 0;
            rep(k, 0, n){
                rep(l, 0, n){
                    if(x[k].first - x[l].first == dif.first && x[k].second - x[l].second == dif.second) count++;
                }
            }
            ma = max(ma, count);
        }
    }


    cout << n - ma << endl;
    return 0;
}
