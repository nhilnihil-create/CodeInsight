#include<iostream>

using namespace std;
void maxHeapify(int A[], int n, int i ) {
	int L = i * 2;
	int R = i * 2 + 1;

	int largest=i;
	if( L <= n && A[largest] < A[L] ) largest = L;
	if( R <= n && A[largest] < A[R] ) largest = R;
    
    if( largest != i ) {
    	swap( A[i], A[largest] );
        maxHeapify( A, n, largest );
    }
}
void buildMaxHeap(int A[], int n) {
    for ( int i = n/2; i > 0; i-- ) {
         maxHeapify( A, n, i);
    }
}

int main() {
	int n;
	cin>>n;
	int *A = new int[n+1];
	for ( int i = 1; i < n+1; ++i ) cin >> A[i];

    buildMaxHeap(A,n);
    
    for ( int i = 1; i < n+1; ++i ) cout << " " << A[i];
    cout<<endl;

	return 0;
}
