#include <bits/stdc++.h>

using namespace std;

int N, M, P;
int X[110], sum;

void solve() {
	if (X[M] == 0) {
		cout << 0 << endl;
		return;
	}
	
	int sub = sum;
	sub *= P;
	sub /= 100;
	sum -= sub;
	
	cout << sum / X[M] << endl;
}

int main() {
	while (1) {
		cin >> N >> M >> P; if (N == 0 && M == 0 && P == 0) break;
		M--;
		
		sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> X[i];
			sum += 100 * X[i];
		}
		
		solve();
	}
	
	return 0;
}