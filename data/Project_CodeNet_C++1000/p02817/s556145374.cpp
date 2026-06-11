#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
using graph = vector<vector<int>>;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define all(x) (x).begin(),(x).end()
#define size(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000

#define pb push_back
#define mp make_pair
#define f first
#define s second

template<class T> inline bool chmax(T &a,T b) { if (a<b) { a=b; return true; } return false; }
template<class T> inline bool chmin(T &a,T b) { if (b<a) { a=b; return true; } return false; }

#define FIND(a,b) find(all(a),b)!=a.end()

vector<bool> seen;
bool dfs(const graph &g, int v, int y) {
    seen[v] = true;
    if(find(all(g[v]),y)!=g[v].end())return true;
    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        return dfs(g, next_v,y);
    }
    return false;
}

int main(){
	string s,t;cin>>s>>t;
	cout<<t+s<<endl;
}



