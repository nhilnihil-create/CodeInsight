// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

ll fac(ll x){
    ll tmp = 1;
    for(ll i = 1; i <= x; i++){
        tmp *= i;
        tmp %= INF;
    }
    return tmp;
}

ll power(ll m, ll n){
    if(n == 0) return 1;
    if(n % 2 == 1) return m * power(m, n-1) % INF;
    ll tmp = power(m, n/2);
    return tmp * tmp % INF;
}

int main(){
    ll X, Y;
    cin >> X >> Y;
    ll a = 2 * X - Y, b = 2 * Y - X;
    if(a % 3 != 0 || b % 3 != 0 || a < 0 || b < 0){
        cout << 0 << endl;
        return 0;
    }

    a /= 3;
    b /= 3;

    ll ans = fac(a + b);
    ans *= power(fac(a), INF - 2);
    ans %= INF;
    ans *= power(fac(b), INF - 2);
    ans %= INF;

    cout << ans << endl;

}