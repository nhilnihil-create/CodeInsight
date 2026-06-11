#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1e9+7;

map<int,int> par;
vector<vector<int>> e;
void rec(int now,int p){
	par[now] = p;
	for(int v:e[now]){
		if(v != p)rec(v,now);
	}
}

int main(){
	int n;
	cin >> n;
	ll k;
	cin >> k;
	e.resize(n);
	for(int i = 0;i < n-1;i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	rec(0,-1);
	par[0] = 0;
	map<P,ll> mp;
	for(int i = 1;i < n;i++){
		mp[P(par[par[i]],par[i])]++;
	}

	ll ans = k;
	for(ll i = 1;i <= mp[P(0,0)];i++){
		ans *= (k - i);
		if(ans <= 0){
			cout << 0 << endl;
			return 0;
		}
		ans %= MOD;
	}

	for(auto p:mp){
		if(p.first != P(0,0)){
			for(ll i = 1;i <= p.second;i++){
				ans *= (k - 1 - i);
				if(ans <= 0){
					cout << 0 << endl;
					return 0;
				}
				ans %= MOD;
			}
		}
	}

	cout << ans << endl;
}
