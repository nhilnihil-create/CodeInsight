#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N + 100; i++) {
		if ((int)(i * 1.08) == N) {
			cout << i << endl;
			break;
		}
		if (i == N + 99) {
			cout << ":(" << endl;
		}
	}
	return 0;
}