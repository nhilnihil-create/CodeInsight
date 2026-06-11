#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int& x : arr) cin >> x;
	
	vector<int> sum(n+1);
	map<int, int> freq;
	ll ans = 0;
	freq[0] = 1;
	for(int L = 0, R = 1; R <= n; R++) {
		while(R - L + 1 > k) {
			freq[(L - sum[L] + k) % k]--;
			L++;
		}
		
		
		sum[R] = (sum[R-1] + arr[R-1]) % k;
		ans += freq[(R - sum[R] + k) % k];
		freq[(R - sum[R] + k) % k]++;
	}
	
	cout << ans << endl;
	
}
