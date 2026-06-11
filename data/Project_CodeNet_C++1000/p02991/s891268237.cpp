#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
vector<int> to[100100];
int dist[100100][3];
const int inf = 1e9+7;
int main()
{
	int n,m,s,t;
	cin >> n >> m;
	rep(i,m){
		int x, y;
		cin >> x >> y;
		--x, --y;
		to[x].push_back(y);
	}
	cin >> s >> t;
	--s, --t;
	// 状態を3つ持つ。
	rep(i,n)rep(j,3)dist[i][j] = inf;
	dist[s][0] = 0;
	queue<P> q;
	q.push({s,0});
	while(!q.empty()){
		int v = q.front().first;
		int type = q.front().second;
		q.pop();
		int d = dist[v][type]; 
		int nd = d;
		if(type == 2) nd += 1;

		int ntype = (type + 1)%3;
		for(int nv : to[v]){
			if(dist[nv][ntype] != inf) continue;
			dist[nv][ntype] = nd;
			q.push({nv,ntype});
		}
	}

	int ans =  dist[t][0];
	cout << (ans == inf ? -1 : ans) << endl;
}

