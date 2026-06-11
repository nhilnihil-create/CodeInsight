#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define point pair<int,int>

int N;
point pos[60];

int unit(point d)
{
    int ret = N;
    rep(i, N)
    {
        rep(j, N)
        {
            point p1 = pos[i];
            point p2 = pos[j];
            if(p1.first + d.first == p2.first && p1.second + d.second == p2.second)ret--;
        }
    }
    return ret;
}

signed main()
{
    cin >> N;
    rep(i, N)
    {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }

    if(N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int ans = 100;
    rep(i, N)
    {
        rep(j, N)
        {
            if(i == j)continue;
            point d = {pos[i].first - pos[j].first, pos[i].second - pos[j].second};
            ans = min(ans, unit(d));
        }
    }

    cout << ans << endl;

    return 0;
}
