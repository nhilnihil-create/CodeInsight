#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> G(n);
    vector<pair<int,int>> vp;
    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a,b);
    }

    int k=0;
    vector<int> c(n,0);
    map<pair<int,int>,int> i;
    queue<int> que;
    vector<int> seen(n,0);
    seen[0]=1;
    que.push(0);

    while(!que.empty()){
        int v=que.front();
        que.pop();
        k=max(k,(int)G[v].size());
        int col=1;
        for (int nv:G[v]){
            if (seen[nv]==1) continue;
            if (col==c[v]) col++;
            c[nv]=i[make_pair(v,nv)]=i[make_pair(nv,v)]=col;
            col++;
            seen[nv]=1;
            que.push(nv);
        }
    }
    cout<<k<<endl;
    for (auto p:vp) cout<<i[p]<<endl;
    return 0;

}