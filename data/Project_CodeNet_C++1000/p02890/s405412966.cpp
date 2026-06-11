#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        cnt[a]++;
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) v.push_back(cnt[i]);
    }
    sort(v.begin(), v.end());

    vector<int> sum(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
        sum[i] += sum[i - 1];
        sum[i - 1] += (i - 1) * max((int)v.size() - j, 0);
        while (j < v.size()) {
            if (v[j] < i) {
                sum[i] += v[j];
                j++;
            } else {
                break;
            }
        }
        if (i == n) sum[i] += i * max((int)v.size() - j, 0);
    }

    vector<int> ans(n + 1, 0);
    for (int i = n, j = 0; i >= 1; i--) {
        while (j <= n) {
            if (sum[j] >= i * j) {
                j++;
            } else {
                break;
            }
        }
        ans[i] = j - 1;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}