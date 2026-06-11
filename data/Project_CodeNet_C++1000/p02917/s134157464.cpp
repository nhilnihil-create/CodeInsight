#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[N], B[N];
	for(int k  = 0; k < N-1; k++){
		cin >> A[k];
		B[k] = 0;
	}
	B[0] = A[0];
	B[1] = A[0];
	for(int i = 1; i < N-1; i++){
		if(A[i] < A[i -1]){
			B[i] = A[i];
			B[i+1] = A[i];
		}else{
			B[i+1] = A[i];
		}
	}
	int ans = 0;
	for(int j = 0; j < N; j++){
		ans += B[j];
	}

	cout << ans;

	return 0;
}