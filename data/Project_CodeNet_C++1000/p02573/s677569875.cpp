#include<bits/stdc++.h>
using  namespace std;

vector<vector<int>>g;
bool mark[1000000];
int mx=0;

void dfs(int i){
mx++;
mark[i]=true;
for(int j=0;j<g[i].size();j++){
    if(!mark[g[i][j]])dfs(g[i][j]);
}
}


main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k,l,m,n,o,p;
    while(cin>>m>>n)
    {
        for(i=0; i<=m; i++)mark[i]=false;
        g.assign(m+1,vector<int>());
        for(i=0; i<n; i++)
        {
            cin>>j>>k;
            g[j].push_back(k);
            g[k].push_back(j);
        }
        j=0;
        for(i=1; i<=m; i++)
        {
            if(!mark[i])
            {
                mx=0;
                dfs(i);
            }
            j=max(j,mx);
        }
        cout<<j<<endl;

    }
    return 0;
}
