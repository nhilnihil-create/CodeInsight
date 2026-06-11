//q026.cpp
//Fri Aug 14 22:09:59 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

vector<ll> visited(200000,0);
vector<ll> g[200000];
vector<ll> ans(200000,0);
vector<ll> p(200000,0);

ll score;
ll point;

void dfs(ll z){
	if (visited[z]==0){
		point += p[z];
		ans[z] = point;
		visited[z] = 1;
		rep(i,g[z].size()){
			ll tmp = g[z][i];
			if (visited[tmp]==0){
				dfs(tmp);
			}
		}
		point -= p[z];
	}
}

int main(){
	ll n,q;
	cin >> n >> q;

	rep(i,n-1){
		ll a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	rep(i,q){
		ll c,x;
		cin >> c >> x;
		c--;
		p[c] += x;
	}

	point = 0;
	dfs(0);

	rep(i,n){
		cout << ans[i] << " ";
	}
	printf("\n");
//	printf("%.4f\n",ans);
}