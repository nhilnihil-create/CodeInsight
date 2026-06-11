#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,k,d,e; cin>>n>>k; vector<int> vis(n+1,0);
        for(int i=1;i<=k;i++){
                cin>>d;
                for(int j=1;j<=d;j++){
                        cin>>e; vis[e]=1;
                }
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(!vis[i]) cnt++;
        cout<<cnt<<endl;
}

