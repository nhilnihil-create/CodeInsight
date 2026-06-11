#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod_pow(int n, int e, int mod){
    int ans = 1;
    n = n % mod;
    while(e != 0){
        if(e % 2 == 1){
            ans = (ans * n) % mod;
        }
        e /= 2;
        n = (n * n) % mod;
    }
    return ans;
}


int mod_inv(int n, int mod){
    return mod_pow(n, mod-2, mod);
}

int mod_combination(int n, int k, int mod){
    if(n < k || k < 0) return 0;
    int ans = 1;
    for(int i=1; i<=k; i++){
        ans = (((ans * (n+1-i)) % mod) * mod_inv(i, mod)) % mod;
    }
    return ans;
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int mod = 1e9+7;
    int x, y;
    cin >> x >> y;

    if((x+y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    int u = x - (x+y)/3;
    int v = y - (x+y)/3;

    cout << mod_combination(u+v, u, mod) << endl;
    return 0;
}