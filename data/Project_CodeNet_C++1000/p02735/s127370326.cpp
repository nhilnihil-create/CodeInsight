#include <bits/stdc++.h>

using namespace std;
const int N = 110;
int _w;

int n, m, f[N][N];
char s[N][N];

int main() {
	cin >> n >> m;
	for( int i = 1; i <= n; ++i )
		cin >> (s[i] + 1);
	memset(f, 0x3f, sizeof f);
	if( s[1][1] == '#' ) {
		f[1][1] = 1;
	} else {
		f[1][1] = 0;
	}
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j ) {
			if( i != n ) {
				int w = (s[i][j] == s[i+1][j] || s[i+1][j] == '.') ? 0 : 1;
				f[i+1][j] = min( f[i+1][j], f[i][j] + w );
			}
			if( j != m ) {
				int w = (s[i][j] == s[i][j+1] || s[i][j+1] == '.') ? 0 : 1;
				f[i][j+1] = min( f[i][j+1], f[i][j] + w );
			}
		}
	cout << f[n][m] << endl;
	return 0;
}
