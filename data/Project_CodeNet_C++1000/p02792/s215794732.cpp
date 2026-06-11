#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> cnt(10, vector<int>(10, 0));

void count(int n)
{
    string s;
    s = to_string(n);

    cnt[s[0] - '0'][s[s.size() - 1] - '0']++;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        count(i);

    int ans = 0;
    rep (i, 10)
        rep (j, 10)
            ans += cnt[i][j] * cnt[j][i];
    cout << ans << endl;
    return 0;
}