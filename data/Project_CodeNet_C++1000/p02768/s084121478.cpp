#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    long long int ans = 1;// pow(2, n)
    long long int pow = 2;
    for(int i=0; i<31; i++){
        if(((n>>i) & 1)){
            ans *= pow;
            ans %= MOD;
        }

        pow *= pow;
        pow %= MOD;
    }
    //cout << ans << endl;

    vector<long long int> inverse(2*1e5+1,1);
    for (int i=2; i<=2*1e5; i++){
        inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
    }

    long long int nCa = 1, nCb = 1;
    for(int i=0; i<a; i++){
        nCa *= (n-i);
        nCa %= MOD;
        nCa *= inverse[i+1];
        nCa %= MOD;
    }
    for(int i=0; i<b; i++){
        nCb *= (n-i);
        nCb %= MOD;
        nCb *= inverse[i+1];
        nCb %= MOD;
    }

    ans -= (1 + nCa + nCb);
    ans = (ans % MOD + MOD) % MOD;

    cout << ans << endl;
    return 0;
}