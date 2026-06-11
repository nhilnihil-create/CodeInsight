#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const llint INF = 100000000;
whei(int) G;
whei(bool) b;
int main() {
	int n, m;
	cin >> n >> m;
	G.resize(n);
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
	}
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	queue<Pint> que;
	que.push(Pint(s,0));
	whei(int) dist(n,hei(int)(3,-1));
	dist[s][0] = 0;
	while (!que.empty()) {
		Pint p = que.front();
		que.pop();
		for (int x : G[p.first]) {
				if (dist[x][(p.second+1)%3]!= -1)continue;
				dist[x][(p.second+1)%3] = dist[p.first][p.second] + 1;
				que.push(Pint(x,(p.second+1)%3));
		}
	}

	int ans = dist[t][0];
	if (ans != -1)ans /= 3;
	cout << ans << endl;

	return 0;
}