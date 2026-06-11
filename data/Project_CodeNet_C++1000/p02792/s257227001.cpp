#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	vector<vector<int>> M(10, vector<int>(10, 0));
	int n; cin >> n;
	int c = 1;
	for (int i=1; i<=n; i++) {
		if (i >= c*10) c *= 10;
		int a = i%10;
		int b = i / c;
		M[a][b]++;
	}
	int ret = 0;
	for (int i=1; i<10; i++) {
		for (int j=i; j<10; j++) {
			if (i==j) ret += pow(M[i][j], 2);
			else ret += M[i][j] * M[j][i] * 2;
		}
	}
	cout << ret << endl;
	return 0;
}