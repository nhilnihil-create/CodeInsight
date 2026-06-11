//bayemirov
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

#define pb push_back

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> s(n);
	for (int& x : s) cin >> x;
	int ans = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k] && s[i] + s[j] > s[k] && s[i] + s[k] > s[j] && s[j] + s[k] > s[i])
					ans++;
	cout << ans;
   return 0;
}