#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

vvin edge(1e6);
vin deep(1e6,-1);
vbo visited(1e6,false);

int dfs(int v){
    if(deep[v]!=-1){
        if(!visited[v])return -1;
        return deep[v];
    }
    deep[v]=1;
    int tmp;
    for(auto e:edge[v]){
        tmp=dfs(e);
        if(tmp==-1)return -1;
        deep[v]=max(deep[v],tmp+1);
    }
    visited[v]=true;
    return deep[v];
}

int main(){
    int n;cin>>n;
    vin a(n-1);
    int x1,x2,y1,y2;
    //x vs y = n(x-1)-x(x-1)/2+y-x-1(x<y)
    rep(i,n)rep(j,n-1){
        cin>>a[j];
        if(j>0){
            x1=min(i+1,a[j-1]);
            y1=max(i+1,a[j-1]);
            x2=min(i+1,a[j]);
            y2=max(i+1,a[j]);
            edge[n*(x1-1)-x1*(x1-1)/2+y1-x1-1].push_back(n*(x2-1)-x2*(x2-1)/2+y2-x2-1);
        }
    }
    int ans=-1,tmp;
    rep(i,n*(n-1)/2){
        tmp=dfs(i);
        if(tmp==-1){
            ans=-1;
            break;
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}