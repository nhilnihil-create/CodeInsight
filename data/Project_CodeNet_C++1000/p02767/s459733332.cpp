#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int x[n];
	int s = 0;
	for(int i = 0;i<n;++i) {
		cin >> x[i];
		s += x[i];
	}	
	s/=n;
	int ans = 1e9;
	for(int k : {0,1}) {
		int ca=0;
		for(int i = 0;i<n;++i)
			ca+=(x[i] - s-k) * (x[i] - s-k);
		ans = min(ca, ans);
	}
	cout << ans << endl;
}
