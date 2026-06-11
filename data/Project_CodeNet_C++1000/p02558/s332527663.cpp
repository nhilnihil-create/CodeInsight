#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f(i,n) for(int i=0;i<n;++i)
typedef vector<int> vi;

//UNION FIND
vi siz(200001);
vi par(200001);
void initialize(int n){
    f(i,n){
        par[i]=i;
        siz[i]=1;
    }
}
int find_set(int v){
    if(par[v]==v) return v;
    return par[v]=find_set(par[v]);//Does two things, finds parent of currently asked vertex and also makes all vertices in the path connected to the root vertex
    /*Faster Implementation
        while(v!=par[v]){
            par[v]=par[par[v]];
            v=par[v];
        }
        return v;
    *///log*(n))
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(siz[a]<siz[b])swap(a,b);
        par[b]=a;
        siz[a]+=siz[b];
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    int z,x,y;
    initialize(n);
    f(i,q){
        cin>>z>>x>>y;
        if(z==0){
            union_sets(x,y);
        }
        else{
            if(find_set(x)==find_set(y))cout<<1<<endl;
            else cout<<0<<endl;
        }
    }


    return 0;
}