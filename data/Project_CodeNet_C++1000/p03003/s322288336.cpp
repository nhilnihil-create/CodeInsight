#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 400000;







int main() {

	int N, M;
	cin >> N >> M;

	int S[3000], T[3000];
	
	rep(i, N) {
		cin >> S[i];
	}
	
	rep(i, M) {
		cin >> T[i];
	}

	ll D[2100][2100];
	ll line[2100][2100];
	ll seq[2100][2100];
	ll sum[2100][2100];

	rep(i, N) {
		rep(j, M) {
			if (j == 0) { line[i][j] = 0; }
			else { line[i][j] = (line[i][j - 1] + D[i][j - 1]) % MOD; }

			if (i == 0) { seq[i][j] = 0; }
			else { seq[i][j] = (seq[i - 1][j] + D[i - 1][j]) % MOD; }

			if (i == 0 || j == 0) { sum[i][j] = 0; }
			else { sum[i][j] = (sum[i - 1][j - 1] + line[i - 1][j - 1] + seq[i - 1][j - 1] + D[i - 1][j - 1]) % MOD; }

			if (S[i] != T[j]) { D[i][j] = 0; }
			else { D[i][j] = sum[i][j] + 1; }

			
		}
	}

	ll ans = (1+ sum[N - 1][M - 1] + line[N - 1][M - 1] + seq[N - 1][M - 1] + D[N - 1][M - 1]) % MOD;

	cout << ans;
	system("PAUSE");

}