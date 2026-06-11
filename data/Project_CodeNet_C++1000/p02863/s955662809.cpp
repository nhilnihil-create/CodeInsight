#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, int> P;
typedef long long ll;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXV = 10000;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[ry]>rank[rx]) par[rx]=ry;
        else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};
int main(){
    int n,t;cin>>n>>t;
    vector<pii> dish(n);
    for(int i=0;i<n;++i) cin>>dish[i].first>>dish[i].second;
    sort(dish.begin(),dish.end());
    vector<vector<int> > dp(n+1,vector<int>(t,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<t;++j){
            dp[i+1][j]=dp[i][j];
            int time=dish[i].first;
            int tasty=dish[i].second;
            if(j>=time){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-time]+tasty);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;++i){
        ans=max(ans,dp[i][t-1]+dish[i].second);
    }
    cout<<ans<<endl;
    return 0;
}