#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line



const int inf = 1001001001;
int dist[100005][3];
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> to(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		--a, --b;
		to[a].push_back(b); // 有向グラフ
	}
	int sv, tv;
	cin >> sv >> tv;
	--sv, --tv; //sからtにいけるか。

	rep(i,n)rep(j,3) dist[i][j] = inf;
	queue<P> q;
	q.push(P(sv,0));
	dist[sv][0] = 0;

	while(!q.empty()){
		int v = q.front().first;
		int l = q.front().second;
		q.pop();
		for (int u : to[v]) {
			int nl = (l+1) % 3;
			if (dist[u][nl] != inf) continue;
			dist[u][nl] = dist[v][l]+1;
			q.push(P(u,nl));
		}
	}
	int ans = dist[tv][0];
	if (ans == inf) ans = -1; 
	else ans /= 3;
	cout << ans << endl;
}
