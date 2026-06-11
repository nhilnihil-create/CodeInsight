#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;
	int ans = -1;
	for (int i = 1; i <= 1100; i++) {
		int x = i * 0.08;
		int y = i * 0.1;
		if (x== a && y== b) {
			ans = i;
			break;
		}
	}	
	cout << ans << endl;
    return 0;
}