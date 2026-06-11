#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

long long int modpow(int b, int p){
    long long int num = 1, power = b;
    for(int i=0; i<=30; i++){
        if((p>>i) & 1) num *= power;

        num %= MOD;
        power *= power;
        power %= MOD;
    }
    return num;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long int> gcd(k+1);
    for(int i=k; i>=1; i--){
        //cout << i << " : ";
        gcd[i] = modpow(k/i, n);
        for(int d=2; d<=k/i; d++){
            //cout << d << " ";
            gcd[i] -= gcd[i*d];
            gcd[i] = (gcd[i] % MOD + MOD) % MOD;
        }
        //cout << endl;
        gcd[i] = (gcd[i] % MOD + MOD) % MOD;
    }

    long long int ans = 0;
    for(long long int j=1; j<=k; j++){
        ans += (gcd[j] * j) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}