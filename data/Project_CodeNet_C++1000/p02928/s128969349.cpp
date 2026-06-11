#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    long long int n, k;
    cin >> n >> k;
    long long int a[n], tenti[n] = {0}, AtoA[n] = {0};
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(a[i] > a[j]) tenti[i]++;
            tenti[i] %= MOD;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i] > a[j]) AtoA[i]++;
            AtoA[i] %= MOD;
        }
    }
    long long int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = (ans + tenti[i]*k%MOD)%MOD;
        ans = (ans + AtoA[i]*(((k-1)*k/2)%MOD))%MOD;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
