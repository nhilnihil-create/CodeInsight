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
#include<tuple>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long int ull;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=2e5;

int n,q;
vector<vector<int> > G(MAXN);
vector<bool> visited(MAXN,false);
vector<int> cnt(MAXN,0);

void dfs(int u){
    visited[u]=true;
    for(auto v:G[u]){
        if(!visited[v]){
            cnt[v]+=cnt[u];
            dfs(v);
        }
    }
    return ;
}

int main(){
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for(int i=0;i<q;i++){
        int p,x;cin>>p>>x;
        p--;
        cnt[p]+=x;
    }
    dfs(0);
    for(int i=0;i<n;i++){
        cout<<cnt[i];
        if(i!=n-1) cout<<' ';
    }
    cout<<endl;
    return 0;
}