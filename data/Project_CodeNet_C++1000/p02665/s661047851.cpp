#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    REP(i, n + 1){
        cin >> a.at(i);
    }

    vector<ll> lb(n + 1, 0), ub(n + 1);
    for(ll i = n; i >= 0; --i){
        ub.at(i) = a.at(i);
        if(i + 1 <= n){
            ub.at(i) += ub.at(i + 1);
        }
        if(i <= 60){
            ub.at(i) = min(ub.at(i), 1LL << i);
        }

        if(i == n){
            lb.at(i) = a.at(i);
        }else{
            lb.at(i) = a.at(i) + 1;
        }
    }

    for(ll i = n - 1; i >= 0; --i){
        lb.at(i) = max(lb.at(i), a.at(i) + lb.at(i + 1) / 2);
        ub.at(i) = min(ub.at(i), a.at(i) + ub.at(i + 1));
    }
    for(ll i = 1; i <= n; ++i){
        lb.at(i) = max(lb.at(i), lb.at(i - 1) - a.at(i - 1));
        ub.at(i) = min(ub.at(i), 2 * (ub.at(i - 1) - a.at(i - 1)));
    }

    ll ans = 0;
    REP(i, n + 1){
        if(lb.at(i) > ub.at(i)){
            cout << -1 << endl;
            return 0;
        }
        ans += ub.at(i);
    }
    cout << ans << endl;
    return 0;
}
