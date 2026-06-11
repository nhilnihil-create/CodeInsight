#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")



int main() {

    ll n; cin >> n;
    ll d = 10;
    ll ans = 0;

    if(n%2 == 1){
        cout << 0;
        return 0;
    }

    while(d <= n){
        ans += n/d;
        d *= 5;
    }
    cout << ans;

    return 0;
}
