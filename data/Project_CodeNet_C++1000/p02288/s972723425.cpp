#include <bits/stdc++.h>
using namespace std;

void maxHeap( vector<int> &A, int i )
{
	int H = A.size() - 1;
	int l = i * 2;
	int r = i * 2 + 1;
	int ma = i;
	if( l <= H && A[l] > A[i] ) {
		ma = l;
	}
	if( r <= H && A[r] > A[ma] ) {
		ma = r;
	}
	if( ma != i ) {
		swap( A[i], A[ma] );
		maxHeap( A, ma );
	}
}

int main()
{
	int H;
	cin >> H;
	vector<int> A( H + 1 );
	for( int i = 1; i <= H; i++ ) {
		cin >> A[i];
	}

	for( int i = H / 2; i > 0; i-- ) {
		maxHeap( A, i );
	}

	for( int i = 1; i <= H; i++ ) {
		cout << " " << A[i];
	}
	cout << endl;
}

