#include<iostream>
#include<vector>
using namespace std;
vector<int> edge[100005];
int n,m;
int main(){
    cin>>n>>m;
    int h[100005];
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=0;j<edge[i].size()&&flag;j++){
            if(h[i]<=h[edge[i][j]]){
                flag=false;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return(0);
}