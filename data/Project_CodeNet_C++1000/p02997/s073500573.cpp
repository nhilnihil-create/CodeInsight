#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n,0){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[rx]>rank[ry]) par[ry]=rx;
        else par[rx]=ry;
        if(rank[rx]==rank[ry]) rank[ry]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int cnt(int n){
        int res=0;
        for(int i=0;i<n;++i){
            if(root(i)==i) res++;
        }
        return res;
    }
};

int main(){
    int N,K;cin>>N>>K;
    if(K>(N-1)*(N-2)/2){
        cout<<-1<<endl;
        return 0;
    }
    int M=N*(N-1)/2-K;
    cout<<M<<endl;
    int i=1,j=2;
    while(M--){
        cout<<i<<' '<<j++<<endl;
        if(j>N){
            i++;
            j=i+1;
        }
    }
    return 0;
}