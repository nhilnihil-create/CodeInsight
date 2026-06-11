#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long bigmod(long long a, long long p){
    if(p == 0){
        return 1;
    }
    long long ans = bigmod(a, p/2);
    ans = (ans * ans) % mod;
    if(p % 2 == 1){
        ans = (ans * a) % mod;
    }
    return ans;
}
int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long>gcd(k + 3);
    long long ans = 0;
    for(long long i = k; i >= 1; i--){
        gcd[i] = bigmod(k / i, n);
        for(int j = 2 * i; j <= k; j = j + i){
            gcd[i] = (gcd[i] - gcd[j] + mod) % mod;
        }
        ans = (ans + i * gcd[i]) % mod;
    }
    cout << ans;
    return 0;
}
