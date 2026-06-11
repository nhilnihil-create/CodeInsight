#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n) {
	
	vector<int> ans;
	for(int i = 1; i*i <= n; i++) {
		if(n % i == 0) {
			ans.push_back(i);
			ans.push_back(n/i);
		}
	}
	
	sort(ans.rbegin(), ans.rend());
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	int sum = 0;
	for(int& x : arr) {
		cin >> x;
		sum += x;
	}
	
	vector<int> div = divisors(sum);
	for(int x : div) {
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			a[i] = arr[i] % x;
		}
		
		sort(a.begin(), a.end());
		int up = 0, down = 0;
		for(int i = 0; i < n; i++) {
			up += x - a[i];
		}
		
		for(int i = 0; i < n; i++) {
			down += a[i], up -= x - a[i];
			if(up == down && down <= k) {
				cout << x << endl;
				return 0;
			}
		}
	}
}
