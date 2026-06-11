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

ll k;
vvin edge(100020);

ll dfs(int from,int now){
    ll can;
    if(from==-1)can=k-(ll)1;
    else can=k-(ll)2;
    if(k<=edge[now].size())return 0;
    ll res=(ll)1;
    for(auto e:edge[now]){
        if(e==from)continue;
        res*=can;
        res%=inf;
        can--;
    }
    for(auto e:edge[now]){
        if(e==from)continue;
        res*=dfs(now,e);
        res%=inf;
    }
    return res;
}

int main(){
    int n;cin>>n>>k;
    int a,b;
    rep(i,n-1){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ll ans=k*dfs(-1,1);
    cout<<ans%inf<<endl;
}