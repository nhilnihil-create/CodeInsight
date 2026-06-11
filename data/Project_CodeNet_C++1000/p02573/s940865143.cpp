#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
const int mod=1e9+7;
int a[maxn];
int fa[maxn];
int find(int x){
    if(x==fa[x])return x;
    else return fa[x]=find(fa[x]);
}
void Merge(int x,int y){
     int xx=find(x);
     int yy=find(y);
     if(xx!=yy){
        fa[xx]=yy;
     }
     return ;
}
int f[maxn];
signed  main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    int a,b;
    for(int i=1;i<=N;i++)fa[i]=i;
    for(int i=1;i<=M;i++){
        cin>>a>>b;
        Merge(a,b);
    }
    for(int i=1;i<=N;i++){
        f[find(i)]++;
    }
    int ans=0;
    for(int i=1; i<=N;i++){
       ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}


