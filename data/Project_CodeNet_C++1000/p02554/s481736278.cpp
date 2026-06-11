#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
    ll pMOD(ll x,ll y){
        ll res = 1;
        rep(i,y){
            res = res * x % MOD;
        }
        return res;
    }
int main(){
    int n;
    cin >> n;
    ll ans = pMOD(10,n) - pMOD(9,n) -pMOD(9,n) + pMOD(8,n);
    ans %= MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;

    return 0;
}