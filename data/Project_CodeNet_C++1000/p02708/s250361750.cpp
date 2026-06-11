#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

vector<long long int> inverse;
vector<long long int> f, f_inverse;

void factorial_Initialize(int max){
    vector<long long int> a(max+1,1);
    inverse = a;
    f = a;
    f_inverse = a;

    for (int i=2; i<=max; i++){
        inverse[i]   = MOD - inverse[MOD % i] * (MOD / i) % MOD;
        f[i]         = f[i-1]         * i          % MOD;
        f_inverse[i] = f_inverse[i-1] * inverse[i] % MOD;
    }
}

long long int nCr(int n, int r){
    if(n < r || r < 0) return 0;
    if (n >= f.size()){
        factorial_Initialize(n);
    }
    return f[n] * f_inverse[r] % MOD * f_inverse[n-r] % MOD;
}

int main(){
    long long int n, k;
    cin >> n >> k;

    long long int ans = 0;
    for(long long int i=k; i<=n+1; i++){
        long long int first = (0+i-1) * i / 2;
        long long int last  = (n+(n-i+1)) * i / 2;
        ans += last - first + 1;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}