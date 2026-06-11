#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll A, B, C, D;

ll gcd( ll a, ll b ){
	if ( a < b )
		return gcd( b, a );
	
	int k = a / b;
	if ( a - k * b == 0 )
		return b;
	return gcd( b, a - k * b );
}


// a <= x <= b となるx で dで割り切れる個数
ll f( ll a, ll b, ll d ){
	ll aa = (a+d-1)/d;
	ll bb = b/d;
	return bb-aa+1;
}

int main(){
	cin >> A >> B >> C >> D;
	
	
	
	cout << (B-A+1) - f(A,B,C) - f(A,B,D) + f(A,B,C*(D/gcd(C,D))) << endl;
	return 0;
}

