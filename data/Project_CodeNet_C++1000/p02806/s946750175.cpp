#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	queue<pair<string, int>> q;
	rep(i, N) {
		pair<string, int> p;
		cin >> p.first >> p.second;
		q.push(p);
	}
	string X;
	int ans = 0;
	cin >> X;
	bool judge = false;
	rep(i, N) {
		if (judge) ans += q.front().second;
		if (q.front().first == X) judge = true;
		q.pop();
	}
	cout << ans << endl;
	return 0;
}