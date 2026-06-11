#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
//setprecision(15)

#define MAX 1000000
int minf[MAX + 1];
int p[MAX + 1];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

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

int div(int n) {
	while (n != 1) {
		int d = minf[n];
		if (p[d] == 1) return 1;
		p[d] = 1;
		while (n % d == 0) n = n / d;
	}
	return 0;
}

int main() {
	sieve();
	memset(p, -1, sizeof(p));
	int N; cin >> N;
	int i;
	int pc_flg;
	vector<int> A(N);
	for (i = 0; i < N; i++) cin >> A[i];
	for (i = 0; i < N; i++) {
		int ret = div(A[i]);
		if (ret == 1) break;
	}
	if (i == N) {
		cout << "pairwise coprime" << endl;
		return 0;
	}
	int r = A[0];
	for (int i = 1; i < N; i++) {
		r = gcd(r, A[i]);
	}
	if (r == 1) {
		cout << "setwise coprime" << endl;
		return 0;
	}
	cout << "not coprime" << endl;
}