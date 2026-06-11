#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, d, a;
	cin >> n >> d >> a;
	vector<pair<int, int>> x(n);
	rep(i, n) {
		int p, q;
		cin >> p >> q;
		x[i] = {p, q};
	}
	sort(all(x));
	queue<pair<int, int>> damage;
	ll ans = 0;
	ll sum = 0;
	rep(i, n) {
		int now_x = x[i].first;
		int now_hp = x[i].second;
		while (!damage.empty()) {
			int bomb_x = damage.front().first;
			int bomb_damage = damage.front().second;
			if(bomb_x < now_x){
				damage.pop();
				sum -= bomb_damage;
			}
			else break;
		}
		now_hp -= sum;
		if(now_hp > 0) {
			ll bomb_cnt = (now_hp + a - 1) / a;
			ll bomb_damage = bomb_cnt * a;
			damage.push({now_x + 2 * d, bomb_damage});
			ans += bomb_cnt;
			sum += bomb_damage;
		}
	}
	cout << ans << endl;
	return 0;
}