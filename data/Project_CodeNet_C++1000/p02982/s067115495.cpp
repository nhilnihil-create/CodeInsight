#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i, n) rep(j, d) cin >> x[i][j];
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dis = 0;
            int cnt = 1;
            for (int k = 0; k < d; k++)
            {
                dis += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            while (dis >= cnt * cnt)
            {
                if (dis == cnt * cnt)
                    ans++;
                cnt++;
            }
        }
    }
    cout << ans << endl;
}