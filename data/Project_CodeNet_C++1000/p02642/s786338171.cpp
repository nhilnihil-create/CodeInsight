#include <bits/stdc++.h>
using namespace std;
const int A = 1e6;
vector<int> factor[A + 1];
int freq[A + 1];
int main() {
// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= A; i++)
		for (int j = 1; j * i <= A; j++)
			factor[i * j].push_back(i);
	int n, ans = 0;
	scanf("%d", &n);
	int v[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", v + i);
		freq[v[i]]++;
	}
	for (int i = 0; i < n; i++) {
		bool absent = true;
		freq[v[i]]--;
		for (int f : factor[v[i]])
			if (freq[f])
				absent = false;
		ans += absent;
		freq[v[i]]++;
	}
	cout << ans;
	return 0;
}