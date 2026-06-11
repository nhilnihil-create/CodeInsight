#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<pll> robo(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        robo[i] = {a - b, a + b};
    }

    sort(robo.begin(), robo.end(), [](pll a, pll b) { return a.second < b.second; });

    int ans = 0;
    ll cur = -pow(10, 10);
    for (int i = 0; i < n; i++)
    {
        if (cur > robo[i].first)
            continue;
        ans++;
        cur = robo[i].second;
    }
    cout << ans << endl;
}