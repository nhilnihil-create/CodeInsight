#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
 
ll mod = 1000000007;

ll powmod(int x, int y) {
    ll res = 1;

    rep(i,y) {
        res = res * x % mod;
    }
    return res;
}

int main(void){
    int n;
    cin >> n;

    ll ans = powmod(10, n) - 2*powmod(9, n) + powmod(8, n);
    ans %= mod;
    ans = (ans+mod) % mod;
    cout << ans << endl;
    return 0;
}
