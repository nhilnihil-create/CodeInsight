#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


static const int N = 100;
static const long long INFTY = (1LL << 32);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

long long m[N][N], n;


void Floyd()
{
	for (int k = 0; k < n; ++k){
		for (int i = 0; i < n; ++i){
			if (m[i][k] == INFTY) continue;
			for (int j = 0; j < n; ++j){
				if (m[k][j] == INFTY) continue;
				m[i][j] = std::min(m[i][j], m[i][k] + m[k][j]);
			}
		}
	}
}


int main()
{
	int x; cin >> n >> x;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			m[i][j] = (i == j) ? 0 : INFTY;
		}
	}
	for (int i = 0; i < x; ++i)
	{
		int u, v, d;
		cin >> u >> v >> d;
		m[u][v] = d;
	}

	Floyd();

	bool neg = false;
	for (int i = 0; !neg && i < n; ++i){
			if (m[i][i] < 0) neg = true;
	}

	if (neg) cout << "NEGATIVE CYCLE" << endl;
	else{
		for (int i = 0; i < n; ++i)	{
			for (int j = 0; j < n; ++j) {
				if (j) cout << " ";
				if (m[i][j] == INFTY) cout << "INF";
				else cout << m[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}