#include <iostream>
#include <vector>
using namespace std;
long long MOD = 1e9 + 7;

long long modPow(long long x, long long a) {
    if (a == 1) return x;
    if (a % 2) return (x * modPow(x, a - 1)) % MOD;
    long long t = modPow(x, a / 2);
    return (t * t) % MOD;
}

int main(){
    long long n, ans = 0;
    cin >> n;
    vector<long long> a(n), cnt(61);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += ((a[i] % MOD) * ((n - 1) % MOD)) % MOD;
        ans %= MOD;
        for(long long j = 0; j <= 60; j++){
            if(a[i] & ((long long)1<<j)){
                cnt[j]++;
            }
        }
    }
    for(long long i = 0; i <= 60; i++){
        // cout << i << ":" << cnt[i] << endl;
        ans -= (modPow(2, i+1) * ((cnt[i] * (cnt[i] - 1) / 2) % MOD)) % MOD;
        if(ans < 0) ans += MOD;
    }
    cout << ans;
    return 0;
}