#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define P 1000000007

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	int n, a[200000];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;
	map<int, int> cnt;
	for(int i = 0; i < n; i++) {
		cnt[i + a[i]]++;
		ans += cnt[i - a[i]];
	}
	
	cout << ans << endl;
	return 0;
}