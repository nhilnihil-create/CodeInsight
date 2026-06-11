#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
int main(){
	cin >> N;
	
	vector<int> A(N+1), B(N);
	for ( int i = 0; i < N+1; i++ )
		cin >> A[i];
	for ( int i = 0; i < N; i++ )
		cin >> B[i];
	
	ll result = 0;
	for ( int i = 0; i < N; i++ ){
		int x = min( A[i], B[i] );
		A[i] -= x;
		B[i] -= x;
		result += x;
		
		int y = min( A[i+1], B[i] );
		A[i+1] -= y;
		B[i] -= y;
		result += y;
	}
	
	
	
	cout << result << endl;
	
	return 0;
}

