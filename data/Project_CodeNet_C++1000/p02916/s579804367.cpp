#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int N;
vi A, B, C;

void input_init(void) {
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	B.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> B[i];
	C.resize(N - 1);
	for (int i = 0; i < N - 1; ++i)
		cin >> C[i];
}

int solve(void) {
	int sum = 0;
	int pre = -2;
	for (int i = 0; i < N; ++i) {
		int id = A[i];
		--id;
		sum += B[id];
		if (id == pre + 1)
			sum += C[id - 1];
		pre = id;
	}
	return sum;
}

int main(void) {
	input_init();
	int ans = solve();
	cout << ans << '\n';
	return 0;
}
