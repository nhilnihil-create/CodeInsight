#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,m; cin>>n>>m;
        vector<int> h(n+1);
        for(int i=1;i<=n;i++) cin>>h[i];
        vector<int> ans(n+1,1);
        int u,v;
        for(int i=1;i<=m;i++){
                cin>>u>>v;
                ans[u]&=(h[u]>h[v]);
                ans[v]&=(h[v]>h[u]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(ans[i]) cnt++;
        cout<<cnt<<endl;
}
