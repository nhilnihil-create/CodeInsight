#include<iostream>
#include<cstring>

using namespace std;

const int N=2e5+10;

int n,m;
int p[N];
int Size[N];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        p[i]=i;
        Size[i]=1;
    }
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        int u,v;
        u=find(a);
        v=find(b);
        if(u!=v){
            p[u]=v;
            Size[v]+=Size[u];
        }
    }
    int res=0;
    for(int i=1;i<=n;++i) res=max(res,Size[i]);
    cout<<res<<endl;
    return 0;
}