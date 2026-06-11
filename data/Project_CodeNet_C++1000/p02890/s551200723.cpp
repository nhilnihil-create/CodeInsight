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

    ll x = n, idx = n;
    for(ll k = 1; k <= n; ++k){
        while(1){
            while(idx > 0 && f.at(idx - 1) >= x){ idx--; }
            ll sum = x * (f.size() - idx);
            if(idx > 0){
                sum += cs.at(idx - 1);
            }
            if(sum >= k * x){
                break;
            }else{
                x--;
            }
        }
        cout << x << endl;
    }
    return 0;
}
