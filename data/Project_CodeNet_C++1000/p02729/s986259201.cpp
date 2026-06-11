#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> b;
    rep(i, n) b.push_back(0);
    rep(i, m) b.push_back(1);

    int ans = 0;
    rep(i, b.size()) rep(j, i)
    {
        int sum = b[i] + b[j];
        if (sum % 2 == 0)
            ans++;
    }

    cout << ans << endl;

    return 0;
}