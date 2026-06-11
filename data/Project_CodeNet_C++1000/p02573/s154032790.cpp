#include<bits/stdc++.h>
using namespace std;

struct UnionFind{

    vector<int> r;
    vector<int> count;

    UnionFind(int N):r(N),count(N){
        for(int i=0;i<N;i++){
            r.at(i)=i;
            count.at(i)=1;
        };
    }

    int root(int x){
        return r.at(x)==x?x:r.at(x)=root(r.at(x));
    }

    void unite(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return;
        r.at(y)=x;
        count.at(x)+=count.at(y);
        count.at(y)=0;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    UnionFind UF(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        UF.unite(x,y);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(UF.count.at(i),ans);
    }
    cout<<ans<<endl;
    return 0;
}