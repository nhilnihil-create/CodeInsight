#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

vector<pair<int, int>> v;
int n, t;
int dp[3005][3005];

int f(int i, int x)
{
    if (i == n || x >= t)
        return 0;
    int& sol = dp[i][x];
    if (sol != -1)
        return sol;

    int p, q;
    tie(p, q) = v[i];
    sol = max(f(i + 1, x), q + f(i + 1, x + p));
    return sol;
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(all(v));
    memset(dp, -1, sizeof dp);
    cout << f(0, 0);
}
