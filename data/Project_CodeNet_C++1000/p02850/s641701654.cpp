#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)

vpii adj[310000];
vi rick1(310000);
int rickma = 0;
void dfs(int morty,int jerry,int rick){
	set<int> set1;
	set1.insert(rick);
	int colors = 1;
	FORR(x,adj[morty])if(x.first!=jerry){
		while(set1.count(colors))colors++;
		rick1[x.second] = colors;
		rickma = max(rickma,colors);
		dfs(x.first,morty,colors);
		colors++;
	}
}

int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall
	
	ini(n);
	FOR(i,0,n-1){
		ini(x);
		ini(x1);
		adj[x-1].push_back({x1-1,i});
		adj[x1-1].push_back({x-1,i});
	}
	dfs(0,-1,0);
	out(rickma);
	FOR(i,0,n-1){out(rick1[i]);}














	return 0;
}