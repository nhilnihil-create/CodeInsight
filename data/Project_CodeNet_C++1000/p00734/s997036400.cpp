#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	while ( cin >> n >> m, n || m ) {
		vector<int> a(n);
		int A = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			A += a[i];
		}
		vector<int> b(m);
		int B = 0;
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
			B += b[i];
		}
		int I = -1, J = -1;
		int s = 1e9;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if ( A - a[i] + b[j] == B + a[i] - b[j] ) {
					++cnt;
					if (a[i] + b[j] < s) {
						I = i+1, J = j+1;
						s = a[i] + b[j];
					}
				}
			}
		}
		if (I < 0) cout << -1 << endl;
		else if (cnt > 0) cout << a[I-1] << " " << b[J-1] << endl;
		else cout << I << " " << J << endl;
	}
}