#include <iostream>
using namespace std;
int main() {
	int N, K;cin >> N >> K;
	int MAX = N * (N - 1) / 2 - (N - 1);
	if (K > MAX) {
		cout << -1 << endl;
		return 0;
	}cout << N - 1 + (MAX - K) << endl;
	for (int i = 2; i <= N; i++) cout << "1 " << i << endl;
	int now = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (now == MAX - K) break;
			cout << i << " " << j << endl;
			now++;
		}if (now == MAX - K) break;
	}
}