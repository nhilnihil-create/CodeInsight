#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, n, ans = 0, best = 1e9;
	cin >> x >> n;
	vector<bool> vis(101);
	for (int i = 0; i < n; ++i){
		int foo; 
		cin >> foo;
		vis[foo] = 1;
	}
	for (int i = 0; i <= 101; ++i){
		if (!vis[i] && abs(i - x) < best){
			best = abs(i - x);
			ans = i;
		}
	}
	cout << ans << '\n';
}


