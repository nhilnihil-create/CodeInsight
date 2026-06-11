#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;


long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    int N, lim = 0;
    cin >> N;
    vector<int>A(N), D(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> A.at(i);
        lim = max(lim, A.at(i));//lim:距離の最大値を持っておく
        D.at(A.at(i))++;
    }

    long long ans = 1;
    if (A.at(0) != 0 || D.at(0) != 1){cout << 0; return 0;}
    for (size_t i = 1; i <= lim; i++)
    {
        ans *= modpow(D.at(i - 1), D.at(i), 998244353);
        ans %= 998244353;
    }
    cout << ans;
}