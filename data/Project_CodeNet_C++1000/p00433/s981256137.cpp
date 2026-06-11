#include<iostream>

using namespace std;

int main() {
	
	int A[5] = {};
	int B[5] = {};
	
	for(int i=0;i<4;i++) {
		
	cin >> A[i];
	A[4] += A[i];
	
}

	for(int i=0;i<4;i++) {
		
	cin >> B[i];
	B[4] += B[i];
	
}
	if( A[4] >= B[4] )
	cout << A[4] << "\n";
	
	else
	cout << B[4] << "\n";
	
	
	return 0;
}
