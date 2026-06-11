#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q;
const int N=55;
int a[N],b[N],c[N],d[N];
int ans;
int w[12];                                 //存搜索的数字用
int calc(){
    int res=0;
    for(int i=1;i<=q;i++){
        if(w[b[i]]-w[a[i]]==c[i]) res+=d[i];
    }    
    return res;
}
void dfs(int cur){
    if(cur>n){
        ans=max(ans,calc());
        return;
    }
    for(int i=w[cur-1];i<=m;i++){
        w[cur]=i;
        dfs(cur+1);
    }
}
int main(){
    
    cin>>n>>m>>q;
    w[1]=1;
    for(int i=1;i<=q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    
    dfs(2);
    
    cout<<ans<<endl;
    
    return 0;
    
}