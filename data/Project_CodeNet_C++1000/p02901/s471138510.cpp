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

int N,M;
vector<int> A,K;
int main(){
    cin>>N>>M;
    A.resize(M);
    K.resize(M);
    fill(K.begin(),K.end(),0);
    for(int i=0;i<M;++i){
        int B;cin>>A[i]>>B;
        for(int j=0;j<B;++j){
            int C;cin>>C;
            K[i]+=(1<<(C-1));
        }
    }
    ll dp[M+1][1<<N];
    for(int i=0;i<=M;++i){
        for(int j=0;j<(1<<N);++j){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<M;++i){
        for(int j=0;j<(1<<N);++j){
            if(dp[i][j]==INF) continue;
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            dp[i+1][j|K[i]]=min(dp[i+1][j|K[i]],dp[i][j]+A[i]);
        }
    }
    if(dp[M][(1<<N)-1]==INF) cout<<-1<<endl;
    else cout<<dp[M][(1<<N)-1]<<endl;
    return 0;
}