#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    // hi + hj = j - i
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[i - a[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mp[i + a[i]];
    }
    cout << ans << endl;

	return 0;
}