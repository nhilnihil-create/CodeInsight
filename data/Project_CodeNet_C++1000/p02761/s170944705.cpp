#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int d[4] = {-1, -1, -1, -1};
	rep(i,M) {
		int s, c;
		cin >> s >> c;
		if (d[s] == -1 ) d[s] = c;
		else if (d[s] != c) {
			cout << -1 << endl;
			return 0;
		}
	}

	if (d[1] == 0) {
		if (N != 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	else if (d[1] == -1) {
		if (N == 1) d[1] = 0;
		else d[1] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (d[i] == -1) d[i] = 0;
		cout << d[i];
	}
	cout << endl;

	return 0;
}
