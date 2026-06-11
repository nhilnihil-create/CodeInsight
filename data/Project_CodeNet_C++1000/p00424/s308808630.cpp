#include <iostream>
using namespace std;
int main() {
	int n;
	aa: cin >> n;
	if (n == 0) {
		goto aaa;
	}
	char a[n], b[n], c;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int m;
	cin >> m;
	char d[m];
	for (int i = 0; i < m; i++) {
		cin >> d[i];
		for (int j = 0; j < n; j++) {
			if (d[i] == a[j]) {
				d[i] = b[j];
				break;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << d[i];
	}
	cout<<endl;
	goto aa;
	aaa: return 0;
}