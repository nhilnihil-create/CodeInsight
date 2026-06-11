#include<bits/stdc++.h>
using namespace std;
int n,m,q;
const int Q=50;
int a[Q],b[Q],c[Q],d[Q];
int ans=0;
int A[10];
void dfs(int x,int before){
    if(x==n){
        int score=0;
        for(int i=0;i<q;i++)if(A[b[i]]-A[a[i]]==c[i])score+=d[i];
        ans=max(ans,score);
    }
    else{
        for(int i=before;i<=m;i++){
            A[x]=i;
            dfs(x+1,i);
        }
    }
    return;
}
int main(){
    cin>>n>>m>>q;
    for(int i=0;i<q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--,b[i]--;
    }
    dfs(0,1);
    cout<<ans<<endl;
    return 0;
}