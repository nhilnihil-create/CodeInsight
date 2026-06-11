#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if (p < 10) {
        vector<int> cnt(p);
        int cur = 0;
        long res = 0;
        cnt[0]++;
        for (int i = 0; i < n; i++) {
            vector<int> cnt2(p);
            for (int j = 0; j < p; j++) {
                cnt2[(j * 10) % p] += cnt[j];
            }
            cnt = cnt2;
            cur = (cur * 10 + (s[i] - '0')) % p;
            res += cnt[cur];
            cnt[cur]++;
        }
        cout << res << "\n";
        return 0;
    }

    int inv10 = 1;
    while ((inv10 * 10) % p != 1) inv10++;

    vector<int> cnt(p);
    int cur = 0;
    long res = 0;
    int inv10pow = 1;
    cnt[0]++;
    for (int i = 0; i < n; i++) {
        cur = (cur * 10 + (s[i] - '0')) % p;
        int xx = (cur * inv10pow) % p;
        res += cnt[xx];
        cnt[xx]++;
        inv10pow = (inv10pow * inv10) % p;
    }
    cout << res << "\n";
    return 0;
}