#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[N], B[N];
	B[0] = 0;
	for(int k = 1; k < N; k++){
		cin >> A[k];
		B[k] = 0;
	}

	for(int j = (N - 1); j > 0; j--){
		B[A[j]-1]++;
	}

	for(int i = 0; i < N; i++){
		cout << B[i] << endl;
	}

	return 0;
}