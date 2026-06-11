#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int maxnum = (n - 1) * (n - 2) / 2;
    if(k > maxnum){
        cout << -1 << "\n";
        return 0;
    }
    vector<pair<int, int>> ans;
    rep(i, n-1){
        ans.emplace_back(1, i + 2);
    }
    int cnt = maxnum - k;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = i+1; j <= n; j++)
        {
            if(cnt == 0)
                break;
            ans.emplace_back(i, j);
            --cnt;
        }
        if(cnt == 0)
            break;
    }
    int m = ans.size();
    cout << m << "\n";
    rep(i, m) cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}