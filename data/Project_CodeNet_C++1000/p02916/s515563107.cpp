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
	
	vector<int> ate(n), sat(n), bonus(n-1);
	
	for (int i = 0; i < n; ++i) cin >> ate[i];
	for (int i = 0; i < n; ++i) cin >> sat[i];
	for (int i = 0; i < n-1; ++i) cin >> bonus[i];
	
	int ans = 0;
	
	for (int i = 0; i < n; ++i) {
		ans += sat[ate[i]-1];
		if (i-1 >= 0 && ate[i-1] +1 == ate[i]) ans += bonus[ate[i-1]-1];
	}
	
	cout << ans;
	
}

