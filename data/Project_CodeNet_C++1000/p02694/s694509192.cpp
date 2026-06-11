#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ll x;
	cin >> x;
	ll money = 100, count = 0;

	while (money < x) {
		money += money / 100;
		count++;
	}
	cout << count << endl;
	return 0;
}