#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n,m;
int d[200005];
int op,u,v;
/*
 4 7
 1 0 1
 0 0 1
 0 2 3
 1 0 1
 1 1 2
 0 0 2
 1 1 3
 */

int find(int u){
    if(d[u]<0) return u;
    return d[u]=find(d[u]);
}

bool union_join(int u, int v){
    int a=find(u);
    int b=find(v);
    if(a==b) return false;
    if(a>b)swap(a, b);
    d[a]+=d[b];
    d[b]=a;
    return true;
}

bool same_set(int u, int v){
    return find(u)==find(v);
}

int main() {
    cin>>n>>m;
    memset(d, -1, sizeof(d));
    while(m--){
        cin>>op>>u>>v;
        if(op==0){
            union_join(u, v);
        }else{
            if(same_set(u, v)) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
