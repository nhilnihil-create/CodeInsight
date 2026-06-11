#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;

int main(void) {
	cin >> N;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> A[i];

	int ans = 0;
	for (int i = 1; i <= N; i += 2) {
		if (A[i] % 2 == 1)
			++ans;
	}

	cout << ans << '\n';
	return 0;
}
