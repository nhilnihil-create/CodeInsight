#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct edge { int to; int cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-10;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

int n,m,s,t;
vector<int> g[300010];
int d[300010];

int main() {
	cin >> n >> m;
	rep(i,m){
		int u,v;
		cin >> u >> v;
		g[u*3].push_back(v*3+1);
		g[u*3+1].push_back(v*3+2);
		g[u*3+2].push_back(v*3);
	}
	cin >> s >> t;
	for(int i = 0; i < 300010; i++) d[i] = INF; d[s*3] = 0;
	queue<int> que; que.push(s*3);
	while(que.size()){
		int p = que.front(); que.pop();
		for(auto a : g[p]){
			if(d[p]+1 < d[a]){
				d[a] = d[p]+1;
				que.push(a);
			}
		}
	}
	if(d[t*3] != INF){
		cout << d[t*3]/3 << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}