#include<iostream>
#include<list>
#include<string>
using namespace std;
int o;
bool b[1000][1000];
void solve(int m, int n, char hw[100][100], char p,int h,int w) {
	if (m + 1 < h&&hw[m + 1][n] == p&&b[m + 1][n] == false) {
		b[m + 1][n] = true;
		o--;
		solve(m + 1, n, hw, p, h, w);
	}
	if (m - 1 >= 0 && hw[m - 1][n] == p&&b[m - 1][n] == false) {
		b[m - 1][n] = true;
		o--;
		solve(m - 1, n, hw, p, h, w);
	}
	if (n + 1 < w&&hw[m][n + 1] == p&&b[m][n + 1] ==false) {
		o--;
		b[m][n + 1] = true;
		solve(m , n+1, hw, p, h, w);
	}
	if (n - 1 >=0&&hw[m][n - 1] == p&&b[m][n - 1] == false) {
		b[m][n - 1] = true;
		o--;
		solve(m, n - 1, hw, p, h, w);
	}
}
int main() {
	int h, w;
	char hw[100][100];
	while (cin >> h >> w&&h != 0 && w != 0) {
		for (int i = 0; i < h; i++) {
			string a;
			cin >> a;
			for (int j = 0; j < w; j++) {
				hw[i][j] = a[j];
				b[i][j] = false;
			}
		}
		o = h*w;
		int m, n;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (b[i][j] == false) {
					m = i;
					n = j;
					b[m][n] = true;
					solve(m, n, hw, hw[m][n], h, w);
				}
			}
		}
		cout << o << endl;
	}
}