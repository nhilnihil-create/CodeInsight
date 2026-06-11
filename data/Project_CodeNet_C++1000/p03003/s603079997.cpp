#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2005
using namespace std;

int M = 1e9 + 7;
int n, m, ans, a[N], b[N], s[N][N], k[N];
void f(int p, int q) {
	int i,j;
	for (i = 0; i < p; i++) {
		for (j =0; j < q; j++) {
			s[p][q] += s[i][j];
		}
	}
}
int main()
{
	int i, j, t;
	cin >> n >> m;
	for (i = 1; i <= n; i++) scanf ("%d", &a[i]);
	for (i = 1; i <= m; i++) scanf ("%d", &b[i]);
	for (i = 0; i <= m; i++) s[0][i] = 1;
	for (i = 1; i <= n; i++) {
		s[i][0] = 1;
		k[0] = 0;
		for (j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				t = s[i - 1][j - 1];
			} else t = 0;
			k[j] = (k[j - 1] + t) % M;
			s[i][j] = (s[i - 1][j] + k[j]) % M;
			ans = (ans + t) % M;
		}
	}
	cout << (ans + 1) % M << endl;
    return 0;
}
