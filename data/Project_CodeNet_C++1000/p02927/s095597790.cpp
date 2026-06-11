#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int m, d;
	cin >> m >> d;
	int ans = 0;
	
	for(int i = 1; i <= m; i++) {
		for(int j = 22; j <= d; j++) {
			if(j % 10 < 2) continue;
			ans += (j/10)*(j%10) == i;
		}
	}
	cout << ans << endl;
}
