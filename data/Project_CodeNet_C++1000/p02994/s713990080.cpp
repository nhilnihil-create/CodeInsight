#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;

int main() { 
	int n;
	cin >> n;
	int l;
	cin >> l;
	int sum = ((n * (n + 1)) / 2)  + n * l - n * 1;
	int ans = 1e9;
	int p = sum;
	for (int i = 1; i <= n; ++i) {
		int a = abs(sum - (sum - (l + i - 1))); 
		if (a < ans) {
			ans = a;
			p = sum - (l + i - 1);
		}
	}
	cout << p;
	return 0; 
} 

