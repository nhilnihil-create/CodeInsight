#include <bits/stdc++.h>

using namespace std;

#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define ull unsigned long long int

const int INF = 1e9 + 7;
const int N = 1e5+5;


int main() {

	IO;

	int n;
	cin >> n;
	
	vector<vector<int>> a(9, vector<int>(9));
	
	for (int i = 1; i <= n; ++i) {
		if (i % 10 == 0) continue;
		
		int x = i % 10;
		int t = 1;
		int m = i;
		while (m > 0) {
			t = m;
			m/=10;
		}
		
		a[t-1][x-1]++;
	}
	
	int ans = 0;
	
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			ans += a[i][j] * a[j][i];
		}
	}
	
	cout << ans;
	
}
