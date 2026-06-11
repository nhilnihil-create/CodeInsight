	#include <bits/stdc++.h>

	#define ll long long int
	#define ull unsigned long long int
	#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	using namespace std;

	const int INF = 1e9 + 7;
	const int N = 1e5+5;

	int main() {

		IO; 
		
		
		int n;
		cin >> n;
		
		vector<int> ar(n);
		for (int i = 0; i <n; ++i) {
			cin >> ar[i];
		}
		
		int low, high;
		high = low = ar[0];
		for (int i = 0; i < n; ++i) {
			low = min(low, ar[i]);
			high = max(high, ar[i]);
		}
		
		ll tot = INF;
		for (int i = low; i <= high; ++i) {
			ll current = 0;
			for (int j = 0; j < n; ++j) {
				current += (ar[j] - i) * (ar[j] - i);
			}
			tot = min(tot, current);
				
		}
		
		cout << tot;
		
	}
