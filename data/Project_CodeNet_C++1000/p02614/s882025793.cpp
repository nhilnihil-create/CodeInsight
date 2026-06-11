#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)
int H, W, K;

//初見×
//bit全探索について理解すること
int main()
{
    cin >> H >> W >> K;
    vector<string> s(H);
    rep(i, H) cin >> s[i];
    int ans = 0;
    rep(is, 1 << H) rep(js, 1 << W)
    {
        int cnt = 0;
        rep(i, H) rep(j, W)
        {
            if ((is >> i) & 1)
                continue;
            if ((js >> j) & 1)
                continue;
            if (s[i][j] == '#')
                cnt++;
        }
        if (cnt == K)
            ans++;
    }
    cout << ans << endl;
}
