#include <iostream>
#include <map>
using namespace std;


int main() {
	int n;
	cin >> n;
	bool ok = true;
	map<int, bool> vis;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if(ok)
			ok = !vis[x];
		vis[x] = true;
	}
	cout << (ok ? "YES" : "NO");
}
