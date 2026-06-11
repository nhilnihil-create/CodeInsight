#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, n;
	cin >> x >> n;
	vector<int> a(n);
	int ans = -1;
	int best = 1e9;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	set<int> s(a.begin(), a.end());
	for (int i = 0; i <= 101; ++i){
		if (s.find(i) == s.end()){
			if (abs(x - i) < best){
				ans = i;
				best = abs(x - i);
			}
		}
	}
	cout << ans << '\n';
}


