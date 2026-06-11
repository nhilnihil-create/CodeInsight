#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll m, d;
    cin >> m >> d;
    ll ans = 0;
    for(ll i = 1; i <= m; ++i){
        for(ll j = 1; j <= d; ++j){
            const auto j1 = j % 10;
            const auto j10 = j / 10;
            if(j1 >= 2 && j10 >= 2 && j1 * j10 == i){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
