/*
 ╔═══╦═══╦═══╗
 ║╔═╗║╔══╩╗╔╗║
 ║║░║║╚══╗║║║║
 ║║░║║╔══╝║║║║
 ║╚═╝║╚══╦╝╚╝║
 ╚══╗╠═══╩═══╝
 ░░░╚╝░░░░░░░░
 */

#include <bits/stdc++.h>
#define ll					long long
#define MOD					1000000007
#define MAX					1e9
#define MIN                 -1e9
#define PI					acos(-1.0)
#define vi					vector<int>
#define vii					vector<vi>
#define vll					vector<ll>
#define mid(s,e)			(s+(e-s)/2)
#define clz(n)				__builtin_clzll(n)

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void printVec(const T &v, char sep=' ') {for (auto &i: v) cout << i << sep;}
template<typename T>
void printVecPair(const T &v, char sep=' ') {for (auto &i: v) cout << i.first <<" " << i.second<< sep;}


#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
vii adj;
ll ans = 1;
bool visited[110000];
int k;
void dfs(int a, int p) {
	visited[a] = true;
	ans = (ans * (k-p))%MOD;
	if(adj[a].size() > 2) {
		int j = 2;
		for(int child: adj[a]) {
			if(!visited[child]) {
				dfs(child,j++);
			}
		}
	}else {
		for(int child: adj[a]) {
			if(!visited[child]) {
				dfs(child,(int)adj[a].size());
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n>>k;
	adj.resize(n+1);
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int root = -1;
	for(int i=1;i<=n;i++) {
		if(adj[i].size() == 1) {
			root = i;
			break;
		}
	}
	dfs(root, 0);
	cout<<ans%MOD<<endl;
	
	return 0;
}




