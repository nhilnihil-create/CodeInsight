#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int main()
{
	int n, m;
	cin >> n >> m;

	int A[n][m];
	REP(i, n){
		REP(j, m){
			cin >> A[i][j];
		}
	}
	int B[m];
	REP(i, m){
		cin >> B[i];
	}

	int C[n];

	REP(i, n){
		int tmp = 0;
		REP(j, m){
			tmp += A[i][j] * B[j];
		}
		C[i] = tmp;

	}

	for (auto x : C){
		cout << x << endl;
	}
}

