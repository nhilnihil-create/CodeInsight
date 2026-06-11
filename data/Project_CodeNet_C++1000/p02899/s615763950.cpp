#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	vector<int> v(n), ans(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++) {
		ans[v[i]-1] = i+1;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

}