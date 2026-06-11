#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int N; cin >> N;
	int a[600];
	fill(a, a+600, INT_MAX);
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	cout << "node 1: key = " << a[1] << ", left key = " << a[2] << ", right key = " << a[3] << ", " << endl;
	for (int i = 2; i <= N; i++) {
		cout << "node " << i << ": key = " << a[i] << ", parent key = " << a[i / 2];
		if (a[i * 2] != INT_MAX) {
			cout << ", left key = " << a[i * 2];
			if (a[i * 2 + 1] != INT_MAX) {
				cout << ", right key = " << a[i*2+1] << ", " << endl;
			}
			else cout << ", " << endl;
		}
		else cout << ", " << endl;
	}
}
