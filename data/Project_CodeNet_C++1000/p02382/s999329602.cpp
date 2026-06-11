#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

int main() {
	
	int n;
	
	while( cin >> n ) {
		
		int A[100] = {};
		int B[100] = {};
		int C[100] = {};
		long long P[3] = {};
		
		for(int i=0;i<n;i++)
		cin >> A[i];
		for(int i=0;i<n;i++)
		cin >> B[i];
		
		for(int i=0;i<n;i++) {
			
			P[0] += abs( A[i] - B[i] );
			P[1] += pow(abs( A[i] - B[i] ), 2);
			P[2] += pow(abs( A[i] - B[i] ), 3);
			C[i] = abs(A[i] - B[i]);
		}
		sort(C, C+n);
		cout << fixed << setprecision(8) << (double) P[0] << "\n"
		 	 << sqrt(P[1]) << "\n"
		 	 << cbrt(P[2]) << "\n"
		 	 << (double) C[n-1] << "\n";
	}
	return 0;
}
