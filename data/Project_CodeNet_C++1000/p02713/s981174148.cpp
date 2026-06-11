#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



ll k;
ll gcdtable[201][201];

ll gcd( ll a, ll b ){
	if ( a < b )
		return gcd( b, a );
	
	int k = a / b;
	if ( a - k * b == 0 )
		return b;
	return gcd( b, a - k * b );
}



int main(){
	cin >> k;
	
	for ( int i = 1; i <= k; i++ ){
		for ( int j = 1; j <= k; j++ ){
			gcdtable[i][j] = gcd( i, j );
		}
	}
	
	ll result = 0;
	for ( int a = 1; a <= k; a++ ){
		for ( int b = 0; b <= k; b++ ){
			ll ab = gcdtable[a][b];
			for ( int c = 0; c <= k; c++ ){
				result += gcdtable[ab][c];
			}
		}
	}
	
	cout << result << endl;
	
	return 0;
}


