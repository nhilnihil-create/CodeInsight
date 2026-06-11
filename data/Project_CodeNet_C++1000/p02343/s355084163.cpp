#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

int  n,q;
int par[10000];
int rank[10000];

void init(int n){
    REP(i,n){
        par[i]=i;
        rank[i]=0;
    }
    return;
}

int find(int x){
    if(par[x]==x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rank[x]<rank[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
    return;
}

bool same(int x,int y){
    return find(x)==find(y);
}
int main(){
  cin >> n >> q;
    init(n);
    REP(i,q){
        int com,x,y;
        cin >> com >> x >> y;
        if(com==1){
            if(same(x,y)) cout << 1 << endl;
            else cout << 0 << endl;
        }else{
            unite(x,y);
        }
    }
  return 0;
}