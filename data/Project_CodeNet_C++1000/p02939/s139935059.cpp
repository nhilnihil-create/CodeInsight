#include <bits/stdc++.h>

using namespace std;
const int N = 200010;
int _w;

int n;
char str[N];

bool check( int l1, int r1, int l2, int r2 ) {
	if( (r1-l1) != (r2-l2) ) return true;
	if( l2 < 0 ) return false;
	for( int i = 0; i <= (r1-l1); ++i )
		if( str[l1+i] != str[l2+i] )
			return true;
	return false;
}

int f[N][3];

void dp() {
	f[0][0] = 0;
	for( int i = 1; i <= n; ++i )
		for( int j = 0; j < 3 && j < i; ++j ) {
			if( check(i-j, i, i-j-1, i-j-1) )
				f[i][j] = max( f[i][j], f[i-j-1][0] + 1 );
			if( check(i-j, i, i-j-2, i-j-1) )
				f[i][j] = max( f[i][j], f[i-j-1][1] + 1 );
			if( check(i-j, i, i-j-3, i-j-1) )
				f[i][j] = max( f[i][j], f[i-j-1][2] + 1 );
		}
	cout << *max_element(f[n], f[n]+3) << endl;
}

int main() {
	cin >> (str+1);
	n = (int)strlen(str+1);
	dp();
	return 0;
}
