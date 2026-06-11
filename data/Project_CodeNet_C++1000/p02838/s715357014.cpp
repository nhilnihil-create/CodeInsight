#include <iostream>
using namespace std;
const int MOD = 1000000007;
int N;
int dig[60];
long long A[300100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
  
    long long ans = 0, dig = 1;
    for (int i = 0; i < 60; i++) {
        long long zero = 0, one = 0;
        for (int j = 0; j < N; j++) {
            long long bit = A[j];
            if ((bit >> i) & 1) one++;
            else zero++;
        }
        ans += (zero * one % MOD) * dig % MOD;
        ans %= MOD;
        dig *= 2;
        dig %= MOD; 
    }
    cout << ans << endl;
}   