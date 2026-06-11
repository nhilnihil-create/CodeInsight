#include <iostream>
using namespace std;
int main() {
	int n, m, a[1010], s = 0, c = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < n; i++)
		if (a[i]*4*m >=s)
			c++;
	if (c >= m) cout << "Yes";
	else cout << "No";
}