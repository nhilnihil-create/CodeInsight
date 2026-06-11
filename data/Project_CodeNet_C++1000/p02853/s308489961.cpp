#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int x, y;
	cin >> x >> y;
	int sum = 0;
	if (x == 3)sum += 100000;
	else if (x == 2)sum += 200000;
	else if (x == 1)sum += 300000;

	if (y == 3)sum += 100000;
	else if (y == 2)sum += 200000;
	else if (y == 1)sum += 300000;

	if (x == 1 && y == 1)sum += 400000;
	cout << sum << endl;
	return 0;
}

