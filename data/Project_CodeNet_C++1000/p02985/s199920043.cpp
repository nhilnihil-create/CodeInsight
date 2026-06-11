#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 10000000000000000;
const int mod = 1000000007;
int test[12345678], kari[345678], aa[12345678];
signed main() {
	int n, k, a, b, ans = 1; cin >> n >> k;
	vector<vector<int> > G(123456);
	for (int h = 1; h < n; h++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<int> que; queue<int> mae; ans *= k;
	for (int i = 0; i < G[1].size(); i++) {
		que.push(G[1][i]); mae.push(1);
		test[1]++; ans *= (k - test[1]); ans %= mod;
	}
	while (que.size()) {
		for (int i = 0; i < G[que.front()].size(); i++) {
			if (G[que.front()][i] != mae.front()) {
				que.push(G[que.front()][i]); mae.push(que.front());
				test[que.front()]++; ans *= (k - test[que.front()] - 1); ans %= mod;
			}
		}
		que.pop(); mae.pop();
	}
	cout << ans % mod << endl;
	cin >> n; return 0;
}