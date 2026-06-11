#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int N, M;
vector<ll> A;



ll gcd( ll a, ll b ){
	if ( a < b )
		return gcd( b, a );
	
	int k = a / b;
	if ( a - k * b == 0 )
		return b;
	return gcd( b, a - k * b );
}



int main2(){
	cin >> N >> M;
	A.resize(N);
	
	for ( int i = 0; i < N; i++ ){
		cin >> A[i];
		A[i] /= 2;
	}
	
	int div = 1;
	{
		ll x = A[0];
		while ( x % 2 == 0 ){
			div *= 2;
			x /= 2;
		}
	}
	
	ll X = A[0];
	for ( int i = 1; i < N; i++ ){
		if ( A[i] % div != 0 || A[i] % (div*2) == 0 )
			return 0;
		X = X * A[i] / gcd( X, A[i] );
		if ( X > M )
			return 0;
	}
	int result = (M / X + 1)/2;
	return result;
}

int main(){
	int result = main2();
	cout << result << endl;
	return 0;
}


