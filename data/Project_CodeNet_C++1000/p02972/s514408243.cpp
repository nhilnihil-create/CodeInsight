#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[200010], b[200010]; 
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i+1];

	int m = 0;
	for (int i = n; i >= 1; i--)
	{
		int sum = 0;
		for (int j = i; j <= n; j += i) sum += b[j];
		if (sum % 2 != a[i]) {
			b[i]++;
			m++;
 		}
	}
	
	cout << m << endl;
	rep(i,n) {
		if (b[i+1]) cout << i+1 << ' ';
	}
	if (m > 0) cout << endl;
	return 0;
}