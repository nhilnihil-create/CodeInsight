#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll n, k, ans=1, M=1e9+7;
vector<int> gr[100005];

ll dfs(ll p, ll q, ll r) {
	ll c;
	if(k-r>0) ans = ans * (k-r) % M;
	else ans = 0;
	c = q ? 2 : 1;
	for(int x:gr[p]) {
		if(x!=q) dfs(x, p, c++);
	}
}

int main() {
	ll i, t1, t2;
	cin >> n >> k;
	while(--n) {
		scanf("%lld%lld", &t1, &t2);
		gr[t1].push_back(t2);
		gr[t2].push_back(t1);
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}