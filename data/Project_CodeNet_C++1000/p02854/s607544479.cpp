#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int n;
ll cum[200002]; 
int main() {
	cin >> n;
	rep(i, n) {
		int A;
		cin >> A;
		if (i==0) cum[i] = A;
		else cum[i] = cum[i-1] + A;
	}
	ll mi = cum[n-1];
	rep(i, n) {
		ll now = abs(cum[i]-(cum[n-1]-cum[i]));
		mi = min(mi, now);
	}
	cout << mi << endl;
}