#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

int main() {
    long long MOD = 1000000007;
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    long long ans = 0;
    long long pow = 1;
    for (int bit = 0; bit < 60; bit++) {
        long long one = 0;
        long long zero = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1LL << bit)) one++;
            else zero++;
        }
        long long sum = ((one * zero) % MOD) * (pow % MOD);
        ans = (ans + sum) % MOD;
        pow = (pow * 2) % MOD;
    }

    cout << ans << endl;
}
