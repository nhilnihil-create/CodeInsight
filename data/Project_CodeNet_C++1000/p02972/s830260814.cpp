#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a(N + 1), ans(N + 1, 0), res;
    rep(i, N) { cin >> a[i + 1]; }
    for (int i = N; i >= 1; i--) {
        int cnt = 0;
        for (int j = 2 * i; j <= N; j += i) {
            if (ans[j] == 0)
                continue;
            else
                cnt++;
        }

        if (a[i] != cnt % 2) {
            ans[i] = 1;
            res.push_back(i);
        }
    }

    cout << res.size() << endl;
    rep(i, res.size()) { cout << res[i] << " "; }
}