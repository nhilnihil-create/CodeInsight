#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

int N;
vector<pii> V[20];

signed main()
{
    cin >> N;
    rep(i, N)
    {
        int a;
        cin >> a;
        rep(j, a)
        {
            int x, y;
            cin >> x >> y;
            x--;
            V[i].push_back({x, y});
        }
    }

    int ans = 0;
    rep(i, 1 << N)
    {
        bool flag = false;
        rep(j, N)if(i & (1 << j))
        {
            for(auto e : V[j])
            {
                if(e.second != ((i >> e.first) & 1))flag = true;
            }
        }
        if(!flag)
        {
            int tmp = 0;
            rep(j, N)if(i & (1 << j))tmp++;
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}
