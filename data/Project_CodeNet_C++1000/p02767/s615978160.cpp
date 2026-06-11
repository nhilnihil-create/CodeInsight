#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	int x[101];
	int ans = 100000007;
	int N;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	for (int j = 0; j < 101; j++) {
		for (int i = 0; i < N; i++) {
			sum += (j - x[i]) * (j - x[i]);
		}
		if (ans > sum)ans = sum;
		sum = 0;
	}
	cout << ans << endl;
	return 0;
}