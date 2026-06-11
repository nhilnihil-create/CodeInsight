#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll M,D;
    cin >> M >> D;
    ll ans = 0;
    for (ll i = 1; i <= D; i++){
        for (ll j = 1; j <= M; j++){
            ll d1 = i % 10;
            ll d2 = i / 10;
            if (d1 >= 2 && d2 >= 2 && d1 * d2 == j) ans++;
        }
    }
    cout << ans << endl;
}
