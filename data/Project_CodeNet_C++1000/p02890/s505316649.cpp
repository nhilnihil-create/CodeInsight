#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    sort(a.begin(), a.end());
    vector<int> s(N + 1);
    rep(i, N) s[i + 1] = s[i] + a[i]; // sum of [0, i)

    for (int k = 1; k <= N; k++) {
        int l = 0;
        int r = N / k + 1;
        while (l + 1 < r) {
            int c = (l + r) / 2;
            bool ok = [&](int c) {
                int i = lower_bound(a.begin(), a.end(), c) - a.begin();
                int sum = c * (N - i) + s[i];
                return (sum >= c * k);
            }(c);
            if (ok) l = c; else r = c;
        }
        printf("%d\n", l);
    }
}