#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

int main() {
	int N, M;
	int H[100000];
	int A, B;
	int ans[100000];

	memset(ans, 0x00, sizeof(ans));
	cin >> N >> M;

	for (int ii = 0; ii < N; ii++) {
		cin >> H[ii];
	}
	for (int ii = 0; ii < M; ii++) {
		cin >> A >> B;
		if (H[A - 1] > H[B - 1]) {
			ans[B - 1] = -1;
		}
		else if (H[A - 1] == H[B - 1]) {
			ans[A - 1] = ans[B - 1] = -1;
		}
		else {
			ans[A - 1] = -1;
		}
	}
	int cnt = 0;
	for (int ii = 0; ii < N; ii++) {
		if (ans[ii] == 0) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}