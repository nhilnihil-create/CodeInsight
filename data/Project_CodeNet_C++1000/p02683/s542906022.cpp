#include <bits/stdc++.h>
using namespace std;
using ll =long long;

signed main() {
    int n,m,x;
    cin>>n>>m>>x;
    int c[n];
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    int ans=INT_MAX;
    int all = 1<<n;
    for(int i=0;i<all;i++)
    {
        vector<int> lev(m,0);
        int cost=0;
        for(int j=0;j<n;j++)
        {
            if((i>>j) & 1)
            {
                cost += c[j];
                for(int j1=0;j1<m;j1++)
                {
                    lev[j1] += v[j][j1];
                }
            }
        }
        bool flag=1;
        for(int i1=0;i1<m;i1++)
        {
            if(lev[i1]<x)
            {
                flag=0;
            }
        }
        if(flag)
        {
            ans = min(ans,cost);
        }

    }
    if(ans==INT_MAX)
    cout<<-1;
    else
    cout<<ans;
    return 0;
}
