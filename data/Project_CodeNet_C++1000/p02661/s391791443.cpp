#include <iostream>
#include <algorithm>
using namespace std;

double med (long *X, long N){
	sort(X,X+N);
	if (N%2 == 0) return 0.5*(X[N/2-1] + X[N/2]);
	else return X[(N+1)/2-1];
}

int main(void){
	long N;
	cin >> N;
	long A[N], B[N];
	for (long i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}

	double med_min = med(A,N);
	double med_max = med(B,N);
	long N_med;
	if (N%2 ==0) N_med = 2*(med_max-med_min) + 1;
	else  N_med = med_max-med_min + 1;
	
	cout << N_med << endl;

return 0;
}


