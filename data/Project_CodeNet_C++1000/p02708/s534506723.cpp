#include <bits/stdc++.h>
using namespace std;
#define MOD (long long)1000000007

int main() {
    int n,k;
    cin >> n >> k;
    long long ans = 0;
    long long mx,mn;
    for(long long i = k;i <= n + 1;i++){
        mn =i * (i - 1)/2;
        mx =i * (n + (n - i + 1))/2;
        ans += (mx - mn + 1)%MOD;
        ans %= MOD;
    }
    cout << ans;
}