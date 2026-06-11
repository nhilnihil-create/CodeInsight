#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *A=new int[n+1];
	for ( int i=1; i<=n; i++) cin >> A[i];

	for( int i=1; i <= n; ++i) {
		cout << "node " << i << ": key = " << A[i] << ", ";
		if ( i>1 ) cout << "parent key = " << A[i/2] << ", ";
		if ( 2 * i <= n ) cout << "left key = " << A[ 2 * i ] << ", ";
		if ( 2 * i + 1 <= n) cout << "right key = " << A[ 2 * i + 1 ] << ", ";
		cout << endl; 
	}
}
