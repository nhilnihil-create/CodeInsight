#include <bits/stdc++.h>
using namespace std;
const int M=1100000;
int dp[M][2],n;
string s;
int zhuan(char c) {
	return c-'0';
}
int main(){
	cin >> s;
	n = s.size() - 1;
	memset ( dp , 0x3f ,sizeof dp);
	dp[ 0 ][ 0 ] = 0;dp[ 0 ][ 1 ] = 1 ;
	for (int i = 0 ; i <= n ; i ++){
		int num = zhuan ( s[ i ] );
		dp[ i + 1 ][ 0 ] = min ( dp[ i ][ 0 ] + num , dp[ i ][ 1 ] + ( 10 - num ) ); 
		dp[ i + 1 ][ 1 ] = min ( dp[ i ][ 0 ] + num + 1, dp [ i ][ 1 ] + ( 10 - num - 1 ) ); 
	}
	int ans = dp [ n + 1 ][ 0 ];
	cout << ans << endl;
	return 0;
}