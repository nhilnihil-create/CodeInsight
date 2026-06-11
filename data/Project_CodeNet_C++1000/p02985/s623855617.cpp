#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

vector<int> tree[100001];
bool reached[100001];

ll prem(int x, int y){
	ll tmp = 1;
	for (int i = x; i > x - y; i--){
		tmp *= i;
		tmp %= MOD;
	}
	return tmp;
}

ll dfs(int now, int color, int depth){
	reached[now] = true;
	int coun = 0;
	for (auto x : tree[now]){
		if (reached[x] == false) coun++;
	}
	if (coun == 0) return 1;
	if (coun > color - depth) return 0;
	ll ans = prem(color - depth, coun);
	for (auto x : tree[now]){
		if (reached[x] == false){
			ans *= dfs(x, color, 2);
			ans %= MOD;
		}
	}
	return ans;
}


int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	cout << k*dfs(1, k, 1)%MOD << endl;
	return 0;
}