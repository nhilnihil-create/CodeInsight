#include<bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define puts(x) cout << x << "\n"
using namespace std;
int n, ans[123456];
vector<pair<int, int>>v[123456];
bool b[123456];
void f1(int d, int c) {
	b[d] = 1;
	int k = 0;
	for (pair<int, int>p1 : v[d]) if (!b[p1.first]) {
		k++; if (k == c)k++;
		ans[p1.second] = k;
		f1(p1.first, k);
		ans[0] = max(ans[0], k);
	}
}
int main() {
	cin >> n;
	for1(i, n - 1) {
		int s, t; cin >> s >> t;
		v[s].push_back(make_pair(t, i));
		v[t].push_back(make_pair(s, i));
	}
	f1(1, 0);
	for0(i, n)puts(ans[i]);
}