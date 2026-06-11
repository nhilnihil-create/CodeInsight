#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
priority_queue<int> pq;

void inin(int a, int b) {
	if (a < b) return;
	vector<int> num(a);
	rep(i,a) cin >> num[i];
	sort(num.begin(), num.end(), greater<int>());
	rep(i,b) pq.push(num[i]);
}
int p;
int main() {
	int x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	inin(a,x);
	inin(b,y);
	rep(i,c) {
		cin >> p;
		pq.push(p);
	}

	ll ans = 0;
	rep(i,x+y) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
	return 0;
}