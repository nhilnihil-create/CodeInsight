#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
using vec = vector<T>;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<int, int> cnt;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        res += cnt[i - a];
        cnt[a + i]++;
    }

    cout << res << '\n';
}