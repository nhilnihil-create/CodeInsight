#include <bits/stdc++.h>

#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
using namespace std;

int main(){
	int n, x, y;	cin >> n >> x >> y;
	int d[n][n];
	int ans[n - 1] = {0};

	x--;
	y--;

	for( int i = 0; i < n; i++ ){
		for( int j = i + 1; j < n; j++ ){
			d[i][j] = min( j - i, abs( x - i ) + abs( y - j ) + 1 );
		}
	}

	for( int i = 0; i < n; i++ ){
		for( int j = i + 1; j < n; j++ ){
			ans[ d[i][j]-1 ]++;
		}
	}

	for( int i = 0; i < n - 1; i++ ){
		cout << ans[i] << endl;
	}

	return 0;
}
