#include <iostream>
#include<vector>
#include <algorithm>
using LL = long long;
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> B(N+1, -100);
	for (int n = 1; n <= N - 1; n++) {
		cin >> B[n];
	}
	B[N] = B[N - 1];
	B[0] = B[1];
	LL res = 0;
	for (int n = 1; n <= N; n++) {
		LL temp = min(B[n], B[n - 1]);
		res += temp;
	}

	cout << res << endl;
	return 0;
}