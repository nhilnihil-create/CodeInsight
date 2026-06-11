#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
#define MAX 1000000
int minf[MAX + 1];
// エラトステネスの篩
void sieve() {
	memset(minf, -1, sizeof(minf));
	for (int i = 2; i <= MAX; i++) {
		if (minf[i] != -1) continue;
		minf[i] = i;
		for (int j = i * 2; j <= MAX; j += i) {
			minf[j] = i;
		}
	}
}
int main() {
	int X; cin >> X;
	sieve();
	while (1) {
		if (minf[X] == X) {
			cout << X << endl;
			return 0;
		}
		X++;
	}
}