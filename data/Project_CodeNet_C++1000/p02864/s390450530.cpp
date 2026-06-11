#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const ll inf = (ll)1e13;const double INF = 1e12, EPS = 1e-9;

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n, k; cin >> n >> k;
	vi h(n + 1);
	rep(i, n) cin >> h[i + 1];
	
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, inf));
	dp[0][0] = 0;
	rep(i, n){
		vector<vector<ll>> next(n + 1, vector<ll>(k + 1, inf));
		rep(p, n + 1) rep(u, k + 1){
			if(u < k) next[p][u + 1] = min(next[p][u + 1], dp[p][u]);
			next[i + 1][u] = min(next[i + 1][u], dp[p][u] + max(0, h[i + 1] - h[p]));
		}
		dp = next;
	}
	ll ans = inf;
	rep(i, n + 1) rep(j, k + 1) ans = min(ans, dp[i][j]);
	cout << ans << endl;
	return 0;
}