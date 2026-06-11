#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7;
bool bad[N];
int memo[N];

int solve (int n) {
    if (n <= 0) return n == 0;
    int &ret = memo[n];
    if (~ret) return ret;
    return ret = (solve(n - 2) + solve(n - 1)) % MOD;
}

int main() {

    int n , m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0 ;i < m ;i++) {
        cin >> a[i];
        bad[a[i]] = 1;
    }

    sort(a.begin() , a.end());

    bool can = !bad[0] && !bad[n];
    for (int i = 1 ;i <= n ;i++)
        if (bad[i] && bad[i - 1])
            can = 0;

    if (!can) {
        cout << 0;
        return 0;
    }

    a.push_back(n + 1);

    memset(memo , -1 , sizeof memo);

    int ans = 1 , prev = -1;
    for (int i = 0 ;i < a.size() ;i++) {
        ans = ans * 1ll * solve(a[i] - prev - 2) % MOD;
        prev = a[i];
    }

    cout << ans;
}
