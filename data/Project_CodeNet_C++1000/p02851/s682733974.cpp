#include <bits/stdc++.h>
#define int long long
#define double long double
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

int n, k, ans = 0;
vector<int> arr;

int ind(int x, vector<int> &arr) {
    if (arr.empty() || arr[0] >= x) {
        return 0;
    } else if (arr.back() < x) {
        return arr.size();
    } else {
        int l = 0;
        int r = arr.size() - 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (arr[m] < x) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
}

void go(int l, int r) {
    if (l == r) {
        if (arr[l] == 1) {
            ans++;
        }
    } else {
        int m = (l + r) >> 1;
        map<int, vector<int>> delta;
        for (int i = m + 1, curr = 0, len = 1; i <= r; i++, len++) {
            curr = (curr + arr[i]) % k;
            int d = (curr - len + k) % k;
            delta[d].push_back(len);
        }
        for (auto pr : delta) {
            int x = pr.first;
            sort(delta[x].begin(), delta[x].end());
        }
        for (int i = m, curr = 0, len = 1; i >= l; i--, len++) {
            curr = (curr + arr[i] % k);
            int d = (curr - len + k) % k;
            ans += ind(k - len, delta[(k - d) % k]);
        }
        go(l, m);
        go(m + 1, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= k;
    }
    go(0, n - 1);
    cout << ans << '\n';

    fflush(stdout);
    return 0;
}
