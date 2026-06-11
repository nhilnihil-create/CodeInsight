#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

#define int long long

const int mxN = 1e7+10;
int spf[mxN];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < mxN; i++) spf[i] = i;
    for (int i = 4; i < mxN; i+=2) spf[i] = 2;
    for (int i = 3; i*i < mxN; i++) {
        if (spf[i] == i) {
            for (int j = i*i; j < mxN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int solve(int x) {
    map<int, int> cnt;
    while (x != 1) {
        cnt[spf[x]] += 1;
        x = x / spf[x];
    }
    int ret = 1;
    for (auto& p : cnt) if (p.second != 0) ret *= p.second+1;
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    sieve();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i*solve(i);
    }

    cout << ans << endl;

    return 0;
}