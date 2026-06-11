#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
	int n; 
	cin >> n;

	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			if (x * y == n) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
}
