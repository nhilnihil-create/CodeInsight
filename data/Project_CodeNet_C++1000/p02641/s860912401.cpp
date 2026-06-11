#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	int x, n, ans;
	cin >> x >> n;
	int p[102] = {};
	rep(i,n) {
		int s;
		cin >> s;
		p[s] = 1;;
	}
	int i = 0;
	while(1) {
		if (p[x - i] == 0) {
			ans = x - i;
			break;
		}
		if (p[x + i] == 0) {
			ans = x + i;
			break;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}
