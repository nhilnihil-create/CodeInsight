#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;



int main(){
	cin >> N;
	
	vector<ll> A(N);
	for ( int i = 0; i < N; i++ )
		cin >> A[i];
	
	vector<ll> acc(N*3+1); // 累積和  a0 - a1 + a2 - a3 + a4 - a5 ....
	acc[0] = 0;
	ll sgn = 1;
	for ( int i = 0; i < 3*N; i++ ){
		acc[i+1] = acc[i] + A[i%N] * sgn;
		sgn = -sgn;
	}
	
	for ( int i = 0; i < N; i++ ){
		if ( i % 2 == 0 )
			cout << (acc[i+N]-acc[i]) << " ";
		else
			cout << (acc[i+2*N]-acc[i+N]) << " ";
	}
	cout << endl;
	
	
	return 0;
}

