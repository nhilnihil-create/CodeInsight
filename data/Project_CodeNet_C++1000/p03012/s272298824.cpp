#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> w(n);
	int s = 0;
	for (int i = 0; i < n; i++){
		cin >> w[i];
		s += w[i];
	}
	int s1 = 0;
	int ans = s;
	for (int i = 0; i < n; i++){
		s1 += w[i];
		s -= w[i];
		ans = min(ans, abs(s1-s));
	}
	cout << ans << '\n';
}
