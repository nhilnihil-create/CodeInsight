#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, Q;
vector<ll> to[200005];
ll num[200005];

void dfs(ll pa, ll cur, ll point) {
	num[cur] += point;
	for(ll next: to[cur]) {
		if(pa == next) continue;
		dfs(cur, next, num[cur]);
	}
}

int main(){
	cin >> N >> Q;

	rep(i, N - 1) {
		ll a, b;
		cin >> a >> b;
		a--;b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	rep(i, Q) {
		ll p, x;
		cin >> p >> x;
		p--;
		num[p] += x;
	}

	dfs(-1, 0, 0);

	rep(i, N) {
		cout << num[i];
		if(i != N - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}

