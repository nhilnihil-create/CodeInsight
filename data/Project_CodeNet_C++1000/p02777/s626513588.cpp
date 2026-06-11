#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s, t, u;
	int a, b; cin >> s >> t >> a >> b >> u;
	cout << a - (s == u) << " " << b - (t == u);


	return 0;
}
