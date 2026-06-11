#include <iostream>
#include <vector>
using namespace  std;
int main() {
	long long int N, M, K;
	cin >> N >> M >> K;
	if (N > K) {
		cout << N - K << endl;
		cout << M <<endl ;
	}
	else if(N+M>K) {
		cout << 0 << endl;
		cout << M-K+N << endl;
	}
	else {
		cout << 0 << endl;
		cout << 0 << endl;
	}
	return 0;
}