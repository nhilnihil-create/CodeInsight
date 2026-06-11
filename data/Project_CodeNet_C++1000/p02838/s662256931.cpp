#include <bits/stdc++.h>
using namespace std;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while(n > 0) {
        if(n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    long long ans = 0;
    long long mod = 1000000007;
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    map<int, long long> pow2{};
    for(long long a : A) {
        int i = 0;
        while(a > 0) {
            if(a & 1)
                pow2[i]++;
            a /= 2;
            i++;
        }
    }
    for(auto itr = pow2.begin(); itr != pow2.end(); ++itr) {
        ans = (ans + modpow(2, itr->first, mod) *
                         (itr->second * (N - itr->second) % mod) % mod) %
              mod;
    }

    cout << ans << endl;
}