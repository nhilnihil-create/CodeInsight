#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define rrep(i,n) for(int (i)=1;i<=(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 1000000007
#define INF 1e18
#define int long long
#define endl "\n"
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};

struct edge {
	int to, index;
};

vector<vector<edge>> graph;
vector<int> ret;

void dfs(int v, int preColor) {
	int color = 1;
	for(auto nextEdge : graph[v]) {
		if(ret[nextEdge.index] == 0) {
			if(color == preColor) color++;
			ret[nextEdge.index] = color;
			dfs(nextEdge.to, color);
			color++;
		}
	}
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
	
	int n;
	cin >> n;
	graph = vector<vector<edge>>(n);
	vector<int> count(n);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge x, y;
		x.to = b, x.index = i;
		y.to = a, y.index = i;
		graph[a].push_back(x);
		graph[b].push_back(y);
		count[a]++, count[b]++;
	}

	int maxCount = 0, maxIndex = -1;
	rep(i, n) {
		if(maxCount < count[i]) {
			maxCount = count[i];
			maxIndex = i;
		}
	}
	cout << maxCount << endl;
	ret = vector<int>(n-1);
	dfs(maxIndex, 0);
	for(auto x : ret) cout << x << endl;
	return 0;
}