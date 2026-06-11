
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

const int N = 1e6 + 5;
int ar[N], cnt[N], spf[N];
int n;

void sieve() {
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < N; i += 2) {
        spf[i] = 2;
    }
    for (int i = 3; i * i < N; i++) {
        if (spf[i] != i) continue;
        for (int j = i * i; j < N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    cin >> n;
    int gc = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mx = max(mx, ar[i]);
        gc = __gcd(gc, ar[i]);
    }
    for (int i = 0; i < n; i++) {
        set<int> cur;
        while (ar[i] != 1) {
            cur.insert(spf[ar[i]]);
            ar[i] /= spf[ar[i]];
        }
        for (auto c: cur) cnt[c]++;
    }
    bool pwcp = true;
    for (int i = 2; i <= mx; i++) {
        // cout << i << ' ' << cnt[i] << '\n';
        if (cnt[i] > 1) pwcp = false;
    }
    if (pwcp) {
        cout << "pairwise coprime" << '\n';
        exit(0);
    }
    if (gc == 1) {
        cout << "setwise coprime" << '\n';
    } else {
        cout << "not coprime" << '\n';
    }
    return 0;
}