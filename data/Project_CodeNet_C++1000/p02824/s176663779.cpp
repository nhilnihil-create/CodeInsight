#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M, V, P;
long long A[1 << 18], B[1 << 18];

int main() {
	cin >> N >> M >> V >> P;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];
	
	vector<int> vec;
	for (int i = 1; i <= N; i++) {
		int pos1 = lower_bound(A + 1, A + N + 1, A[i] + 1) - A;
		int cl = pos1, cr = N - (P - 1);
		if (cl > cr) {
			vec.push_back(i);
		}
		else {
			long long target = A[i] + M;
			long long rem = 1LL * M * max(0LL, V - (N - (cr - cl + 1)));
			int pos2 = lower_bound(A + 1, A + N + 1, target + 1LL) - A;
			if (pos2 > cr) {
				long long val = 1LL * (cr - (cl - 1)) * target - (B[cr] - B[cl - 1]);
				if (val >= rem) vec.push_back(i);
			}
		}
	}
	cout << vec.size() << endl;
	return 0;
}