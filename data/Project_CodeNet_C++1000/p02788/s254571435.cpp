#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAXN = 200000;

pair<int, int> monster[MAXN + 2];

int main() {
	int N, D, A;
	cin >> N >> D >> A;
	for(int i = 0; i < N; i++)
		cin >> monster[i].first >> monster[i].second;
	sort(monster, monster + N);
	queue<pair<int, int>> atk;
	int d = 2 * D + 1;
	ll ans = 0;
	for(int i = 0, cur = 0; i < N; i++) {
		int x = monster[i].first, h = (monster[i].second + A - 1) / A;
		while(!atk.empty() && x >= atk.front().first) {
			cur -= atk.front().second;
			atk.pop();
		}
		if(cur < h) {
			ans += h - cur;
			atk.push({x + d, h - cur});
			cur = h;
		}
	}
	cout << ans << '\n';
}
