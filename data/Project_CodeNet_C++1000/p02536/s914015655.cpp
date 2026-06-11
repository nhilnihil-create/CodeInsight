#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

struct UnionFind{
    vector<int> par;

    UnionFind(int N) : par(N){
        for(int i=0;i<N;i++)    par[i]=i;
    }

    int root(int x){
        if(par[x]==x)   return x;
        return par[x] = root(par[x]);
    }

    void unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry)  return;
        par[rx]=ry;
    }
};

int main(){

    int N,M,count=0;
    cin>>N>>M;
    UnionFind tree(N);

    for(int i=0;i<M;i++){
        int A,B;
        cin>>A>>B;
        A--; B--;
        tree.unite(A,B);
    }
    for(int i=0;i<N;i++){
        if(tree.root(i)==i) count++;
    }

    cout<<count-1<<endl;
    return 0;
}