#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

const int MOD = 1e9+7;

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int sub(int a, int b) {
    int c = a - b;
    if (c < 0) {
        c += MOD;
    }
    return c;
}

int my_pow(int x, int e) {
    if (e == 0) {
        return 1;
    }
    
    if (e % 2 == 0) {
        int temp = my_pow(x, e/2);
        return mul(temp, temp);
    }
    else {
        return mul(x, my_pow(x, e-1));
    }
}

int my_inv(int x) {
    return my_pow(x, MOD-2);
}

int nCk(int n, int k) {
    // n! / (n-k)!*k!
    // return mul(fac[n], my_inv(mul(fac[n-k], fac[k])));
    int ans = 1;
    
    for (int i = 1; i <= k; i++) {
        ans = mul( mul(ans, n-i+1), my_inv(i) );
    }
    
    return ans;
}

int main() {
    int n, a, b;
    int n_fac, a_fac, b_fac;
    
    scanf("%d%d%d", &n, &a, &b);
    
    //vector<int> fac(n+1);
    
    //fac[0] = 1;
 
    
    int ans = my_pow(2, n);
    
    ans = sub(ans, nCk(n, a));
    
    ans = sub(ans, nCk(n, b));
    
    ans = sub(ans, 1); // empty set
    
    //int ans = sub(my_pow(2, n), add(nCk(n, a, fac), nCk(n, b, fac)));
    
    printf("%d", ans);
	
	return 0;
}