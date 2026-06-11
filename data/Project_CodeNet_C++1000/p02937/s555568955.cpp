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
const int INF=1e9;
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
    string S,T;cin>>S>>T;
    ll N,M;
    N=(ll)S.size();M=(ll)T.size();
    vector<vector<ll> > st(26);
    for(int i=0;i<N;++i){
        st[S[i]-'a'].push_back(i+1);
    }
    for(int i=0;i<26;++i){
        if(st[i].size()==0) continue;
        st[i].push_back(INF);
    }
    ll cnt=0;
    ll roop=0;
    for(int i=0;i<M;i++){
        if(st[T[i]-'a'].size()==0){
            cout<<-1<<endl;
            return 0;
        }
        cnt=*lower_bound(st[T[i]-'a'].begin(),st[T[i]-'a'].end(),cnt+1);
        if(cnt==INF){
            roop++;
            cnt=*lower_bound(st[T[i]-'a'].begin(),st[T[i]-'a'].end(),1);
        }
    }
    cout<<N*roop+cnt<<endl;
    return 0;
}