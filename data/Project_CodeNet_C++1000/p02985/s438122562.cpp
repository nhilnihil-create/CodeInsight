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

vector<int> G[100100];

const ll mod = 1e9+7;
int main()
{
	int n, k;
	cin >> n >> k;
	rep(i,n-1){
		int a, b;
		cin >> a >> b;
		--a, --b; 
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<P> que;
	que.push({0,-1});
	ll ans = 1;
	vector<bool> seen(n+1,false);
	ans *= k;
	seen[0] = true;
	while(que.size()){
		auto p = que.front();
		que.pop();
		int now = k-1;
		for(int i = 0; i < G[p.first].size(); i++){
			int x = G[p.first][i]; // 頂点 x を塗る
			if(seen[x]){
				now--;
			}
		}
		for(int i = 0; i < G[p.first].size(); i++){
			int x = G[p.first][i]; // 頂点 x を塗る
			if(x == p.second) continue;
			seen[x] = true;
			ans *= now;
			ans %= mod;
			now--;
			que.push({x,p.first});
		}
	}
	cout << ans << endl;
}
