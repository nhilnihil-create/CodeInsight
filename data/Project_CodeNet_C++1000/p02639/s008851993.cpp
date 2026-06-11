#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	int ans=0;
	for (int i = 1; i <= 5; ++i) {
		cin >> x;
		if (!x) ans=i;
	}
	cout << ans << endl;

}