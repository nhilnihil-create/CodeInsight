#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	int ans = -1;
	for (int i = 1; i <= 1100; i++) {
		if (i * 8 / 100 == a && i * 10 / 100 == b) {
			ans = i;
			break;
		}
	}	
	cout << ans << endl;
    return 0;
}