#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
bool bo[100000] = { false };
int main(){
	int n, k, a, b;
	long long ans = 1, co = 1000000008;
	cin >> n >> k;
	vector<vector<int>> vec(n+10);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		vec[a].emplace_back(b);
		vec[b].emplace_back(a);
	}
	ans *= k;
	k--;
	queue<pair<int,int>> que;
	que.emplace(make_pair(1,0));
	bo[1] = true;
	while (!que.empty()) {
		int k1 = k;
		for (int j = 0; j < vec[que.front().first].size(); j++) {
			if (bo[vec[que.front().first][j]] == false) {
				bo[vec[que.front().first][j]] = true;
				que.emplace(make_pair(vec[que.front().first][j], que.front().second + 1));
				ans = ans * k1 % 1000000007;
				k1--;
			}
		}
		if (que.front().second < 1) {
			if (co != que.front().second) {
				co = que.front().second;
				k--;
			}
		}
		que.pop();
	}
	cout << ans << endl;
}