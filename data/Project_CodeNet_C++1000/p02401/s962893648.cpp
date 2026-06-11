#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const double PI = acos(-1.0);

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	string op;
	while(1) {
		cin >> a >> op >> b;
		int ans;
		if(op == "?") break;
		if(op == "+") ans = a + b;
		if(op == "-") ans = a - b;
		if(op == "*") ans = a * b;
		if(op == "/") ans = a / b;
		cout << ans << "\n";
	}
	
	return 0;
}