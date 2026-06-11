#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define D(x) cerr << #x << " = " << (x) << '\n'
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k, c;
	string s;
	cin >> n >> k >> c >> s;
	c++;
	vector<int> l(k + 2), r(k + 2);
	l[0] = -c;
	for(int i = 1; i <= k; ++ i) {
		int idx = l[i - 1] + c;
		while(s[idx] == 'x') idx++;
		l[i] = idx;
	}
	r[k + 1] = n + c - 1;
	for(int i = k; i >= 1; --i) {
		int idx = r[i + 1] - c;
		while(s[idx] == 'x') idx--;
		r[i] = idx;
	}
	for(int i = 1; i <= k; ++ i) {
		if(l[i] == r[i]) cout << l[i] + 1 << '\n';
	}
}
