#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin >> a >> b;
	int sockets = 1;
	int ans = 0;
	while(sockets < b) {
		sockets--;
		sockets+=a;
		ans++;
	}	
	cout << ans << '\n';
}