#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



const ll MOD = 1000000007;



ll K, N;
/*
	
	   B    R    B    R    B        // N=5, K=3, i=3 の場合
	                                // ここにRとBを追加する方法は何通りか?

	R*   B*   R*   B*   R*   B* R*  
*/

// memo[a][b] : a個の石をb個の箱に、それぞれ0個以上入れる方法
ll memo[2001][2001];

ll f( int a, int b ){
	if ( memo[a][b] != -1 )
		return memo[a][b];
	ll result = 1;
	if ( b <= 1 || a == 0 ){
		result = 1;
	}
	else {
		result = 0;
		for ( int i = 0; i <= a; i++ ){
			// b-1個目までの箱に a-i 個、
			// b個目の箱にi個入れる
			result += f( a-i, b-1 );
		}
	}
	result %= MOD;
	memo[a][b] = result;
	//cout << a << "/" << b << "/" << result << endl;
	return result;
}

int main(){
	cin >> N >> K;
	
	for ( int i = 0; i <= 2000; i++ )
		for ( int j = 0; j <= 2000; j++ )
			memo[i][j] = -1;
	
	for ( int i = 1; i <= K; i++ ){
		// 指定されたiで、Nが最小の場合を考える。
		int Rfix = i-1;
		int Bfix = i;
		
		// 残りのRとBを、i+1個の塊とi個の塊に振り分ける
		int R = (N-K)-Rfix;
		int B = K - Bfix;
		
		if ( R < 0 || B < 0 ){
			cout << 0 << endl;
		}
		else {
			cout << (f(R,i+1)*f(B,i))%MOD << endl;
		}
	}
	
	return 0;
}

