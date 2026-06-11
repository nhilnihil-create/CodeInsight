#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

int N, X, Y;
int ans[2010];

signed main()
{
    cin >> N >> X >> Y;
    for(int i = 1; i <= N; i++)
    {
        vector<int> v(N + 1, -1);
        queue<pii> q;
        q.push({i, 0});
        while(!q.empty())
        {
            pii ele = q.front();
            q.pop();
            if(v[ele.first] == -1)
            {
                v[ele.first] = ele.second;
                if(ele.first != N)q.push({ele.first + 1, ele.second + 1});
                if(ele.first != 1)q.push({ele.first - 1, ele.second + 1});
                if(ele.first == X)q.push({Y, ele.second + 1});
                if(ele.first == Y)q.push({X, ele.second + 1});
                ans[ele.second]++;
            }
        }
    }

    for(int i = 1; i < N; i++)cout << ans[i] / 2 << endl;

    return 0;
}
