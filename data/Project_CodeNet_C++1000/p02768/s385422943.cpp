#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

const long int mod = 1000000007;

long int all(long int n, long int k) {
    if(n == 0)
        return 1;
    
    long int x = all(n/2,k);
    x *= x;
    x %= mod;

    if(n%2 == 1) {
        x *= k;
        x %= mod;
    }
    
    return x;
}

int main() {
    long int n, a, b;
    cin >> n >> a >> b;
    
    long int n_all, a_all, b_all;
    n_all = all(n,2) - 1;
    if(n_all < 0)
        n_all += mod;

    long int c, m;
    
    c = m = 1;
    rep(i,a) {
        c *= n - i;
        c %= mod;
        m *= a - i;
        m %= mod;
    }
    a_all = c * all(mod-2,m);
    a_all %= mod;
    
    c = m = 1;
    rep(i,b) {
        c *= n - i;
        c %= mod;
        m *= b - i;
        m %= mod;
    }
    b_all = c * all(mod-2,m);
    b_all %= mod;

    //cout << n_all << endl;
    //cout << a_all << endl;
    //cout << b_all << endl;
    
    long int ans = n_all - a_all - b_all;
    while(ans < 0) {
        ans += mod;
    }

    cout << ans << endl;
    
    
    return 0;
}


