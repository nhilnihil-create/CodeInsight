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
const int inf=1e9+7;
const ll INF=1e18;

int MAX_N=10050;
int n;
vvin edge(MAX_N);
vin indegree(MAX_N);

//頂点番号0,1,...,n-1
vin topological_sort(){
    vin sorted;
    queue<int> q;
    rep(i,n)if(!indegree[i])q.push(i);
    while(q.size()){
        auto p=q.front();q.pop();
        sorted.push_back(p);
        for(auto e:edge[p]){
            indegree[e]--;
            if(!indegree[e])q.push(e);
        }
    }
    return sorted;
}

int main(){
    int m;cin>>n>>m;
    int s,t;
    rep(i,m){
        cin>>s>>t;
        edge[s].push_back(t);
        indegree[t]++;
    }
    vin ans=topological_sort();
    rep(i,n)cout<<ans[i]<<endl;
}
