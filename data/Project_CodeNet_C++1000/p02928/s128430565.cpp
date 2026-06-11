#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
    long long int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long int count = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = i+1; j < N; j++) {
            if(A[i] > A[j]) {
                count++;
                count %= MOD;
            }
        }
    }
    long long int ans = 0;
    ans = count * K;
    ans %= MOD;
    count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[j] > A[i]) {
                count++;
                count %= MOD;
            }
        }
    }
    ans += ((K * (K-1) / 2) % MOD) * count;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}