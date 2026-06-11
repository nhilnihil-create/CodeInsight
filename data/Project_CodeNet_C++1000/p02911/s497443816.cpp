#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> correct(n, 0);
	rep(i, q) {
		int a; cin >> a;
		correct[a-1]++;
	}
	rep(i, n) {
		int score = k - q + correct[i];
		if (score > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}