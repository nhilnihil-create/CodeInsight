#include <iostream>
using namespace std;

int main() {
	int N, M, ans = 0;
	cin >> N >> M;
	int H[N], Z[N], A[M], B[M];
	for(int k = 0; k < N; k++){
		cin >> H[k];
		Z[k] = 0;
	}
	for(int k = 0; k < M; k++){
		cin >> A[k] >> B[k];
		if(H[A[k]-1] > H[B[k]-1]){
			Z[B[k]-1]++;
		}else if(H[A[k]-1] < H[B[k]-1]){
			Z[A[k]-1]++;
		}else{
			Z[A[k]-1]++;
			Z[B[k]-1]++;
		}
	}

	for(int k = 0; k < N; k++){
		if(Z[k] == 0){
			ans++;
		}
	}

	cout << ans;


	return 0;
}