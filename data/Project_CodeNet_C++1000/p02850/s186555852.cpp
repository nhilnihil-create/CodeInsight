#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

struct edge{int to,id;};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<edge>> g(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back({b,int(i)});
        g[b].push_back({a,int(i)});
    }
    int k=0;
    rep(i,n) chmax(k,int(g[i].size()));
    vector<int> ans(n-1);
    auto dfs=[&](auto &dfs,int v,int pre,int c)->void{
        int now=0;
        for(auto to:g[v]){
            if(to.to==pre) continue;
            now++;
            if(now==c) now++;
            ans[to.id]=now;
            dfs(dfs,to.to,v,now);
        }
    };
    dfs(dfs,0,-1,0);
    cout<<k<<endl;
    cout<<ans<<endl;
}