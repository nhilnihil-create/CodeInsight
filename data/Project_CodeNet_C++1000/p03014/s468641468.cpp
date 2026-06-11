#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int n = 2 * 1e3 + 7;
const int m = 2 * 1e3 + 7;
int down[n][m], up[n][m], lef[n][m], righ[n][m];
char a[n][m];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.') {
				if (j == 0)
					lef[i][j] = 1;
				else
					lef[i][j] = lef[i][j - 1] + 1;

			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = w - 1; j >= 0; j--) {
			if (a[i][j] == '.') {
				if (j == w - 1)
					righ[i][j] = 1;
				else
					righ[i][j] = righ[i][j + 1] + 1;

			}
		}
	}
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (a[i][j] == '.') {
				if (i == 0)
					down[i][j] = 1;
				else
					down[i][j] = down[i - 1][j] + 1;
			}
		}
	}
	for (int j = w - 1; j >= 0; j--) {
		for (int i = h - 1; i >= 0; i--) {
			if (a[i][j] == '.') {
				if (i == h - 1)
					up[i][j] = 1;
				else
					up[i][j] = up[i + 1][j ] + 1;
			}
		}
	}
	int nax = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '.') {
				nax = max(nax, down[i][j] + up[i][j] + lef[i][j] + righ[i][j] - 3);
			}
		}
	}
	cout << nax << endl;
}