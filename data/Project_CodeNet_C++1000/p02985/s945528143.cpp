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

int n,k;
ll ans = 1;
vi v[100010],vv[100010];
int flag[100010];

void dfs(int now, int par){
	flag[now] = 1;
	ans = (ans*(k-vv[par].size()))%MOD;
	//if(par != 0) vv[now].push_back(par);
	for(auto x : v[now]){
		if(flag[x]) continue;
		//vv[par].push_back(x);
		//vv[x].push_back(par);
		vv[now].push_back(x);
		vv[x].push_back(now);
		
		dfs(x,now);
	}
}

int main() {
	cin >> n >> k;
	vi a(n-1),b(n-1);
	rep(i,n-1){
		cin >> a[i] >> b[i];
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	int s;
	for(int i = 1; i <= n; i++){
		if(v[i].size() == 1) s = i;
	}
	dfs(s,0);
	cout << ans << endl;
	return 0;
}