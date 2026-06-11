#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int res = 0;
	for (int i=1; i<=n; ++i) {
		int x; cin >> x;
		if (i%2 && x%2) res++;
	}
	cout << res << endl;
}