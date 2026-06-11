#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll X, K, D; cin >> X >> K >> D;
    X = abs(X);
    if( (__uint128_t)D * (__uint128_t)K <= X ){
        cout << X - D*K << endl;
        return 0;
    }
    ll num = X / D;
    X -= num*D;
    K -= num;
    K%=2;
    if(K == 0) cout << X << endl;
    else cout << abs(X-D) << endl;

}