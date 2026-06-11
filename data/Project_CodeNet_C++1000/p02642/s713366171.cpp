#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 5;

int n;
int a[N];
bool f[N * 5];
int cnt[N * 5];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	vector <int> v;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], v.push_back(a[i]), cnt[a[i]]++;
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	for (int i = 0; i < v.size(); i++) {
		if (f[v[i]] == 0 && cnt[v[i]] == 1) res++;
		for (int j = v[i]; j <= 1000000; j += v[i]) f[j] = 1;
	}
	cout << res;
	return 0;
}