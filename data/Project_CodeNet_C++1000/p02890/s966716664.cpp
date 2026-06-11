#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll n;
    cin >> n;
    vector<ll> f(n, 0);
    REP(i, n){
        ll ai;
        cin >> ai;
        f.at(--ai)++;
    }
    sort(f.begin(), f.end());

    vector<ll> cs(n, 0);
    cs.at(0) = f.at(0);
    for(ll i = 1; i < n; ++i){
        cs.at(i) = cs.at(i - 1) + f.at(i);
    }

    vector<ll> ans(n, 0);
    for(ll k = 1; k <= n; ++k){
        ll lo = 0, hi = n / k + 1;
        while(lo < hi){
            const ll x = (lo + hi + 1) / 2;
            const ll idx = upper_bound(f.begin(), f.end(), x) - f.begin();
            ll sum = x * (f.size() - idx);
            if(idx > 0){
                sum += cs.at(idx - 1);
            }
            if(sum >= k * x){
                lo = x;
            }else{
                hi = x - 1;
            }
        }

        cout << lo << endl;
    }
    return 0;
}
