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

//const ll mod = 998244353;
vector<int> graph[100100];
bool seen[100100];
const ll mod = 1e9+7;

int main()
{
	int n, k;
	cin >> n >> k;
	rep(i,n-1){
		int x, y;
		cin >> x >> y;
		--x,--y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	queue<P> q;
	q.push({0,-1});
	ll ans = k;
	seen[0] = true;
	while(!q.empty()){
		int v = q.front().first;
		int p = q.front().second; q.pop();
		ll color = k-1;
		if(p == -1) color = k-1;
		else {
			// 親の繋がってるところで色塗り済みを数える
			for(auto x:graph[v]){
				if(seen[x]){
					color --;
				}
			}
		}
		for(auto x: graph[v]){
			// いけるのはx.first
			if(seen[x])continue;
			ans *= color;
			ans %= mod;
			color--;
			q.push({x,v});
			seen[x] = true;
		}
	}
	cout << ans << endl;
}
