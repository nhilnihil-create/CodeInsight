#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
const int M = int(1e9) + 7;
int N, K, cnt[MAXN], ans;

int mpow(int a, int p) {
    int res = 1, sqr = a;
    while (p) {
        if (p & 1) res = ((int64_t)res * sqr) % M;
        p >>= 1;
        sqr = ((int64_t)sqr * sqr) % M;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = K+1; i-->1;) {
        cnt[i] = mpow(K/i, N);
        for(int j = i + i; j <= K; j += i) {
            cnt[i] = (M + cnt[i] - cnt[j]) % M;
        }
        ans = (ans + (int64_t)cnt[i] * i) % M;
    }
    cout << ans;
}