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
	long long ans = 1, co = 0;
	cin >> n >> k;
	vector<vector<int>> vec(n+10);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		vec[a].emplace_back(b);
		vec[b].emplace_back(a);
	}
	ans *= k;
	k--;
	queue<int> que;
	que.emplace(1);
	bo[1] = true;
	while (!que.empty()) {
		int k1 = k;
		for (int j = 0; j < vec[que.front()].size(); j++) {
			if (bo[vec[que.front()][j]] == false) {
				bo[vec[que.front()][j]] = true;
				que.emplace(vec[que.front()][j]);
				ans = ans * k1 % 1000000007;
				k1--;
			}
		}
		if (co < 1) {
			k--;
		}
		co++;
		que.pop();
	}
	cout << ans << endl;
}