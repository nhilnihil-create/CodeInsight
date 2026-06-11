#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N, M;
	long long K;
	cin >> N >> M >> K;

	vector<long long> A(N);
	vector<long long> B(M);

	for (long long i = 0; i < N; ++i) {
		cin >> A[i];
		if (i != 0) {
			A[i] += A[i - 1];
		}
	}
	for (long long i = 0; i < M; ++i) {
		cin >> B[i];
		if (i != 0) {
			B[i] += B[i - 1];
		}
	}

	int count = 0;
	int preJ = M - 1;

	for (int i = 0; i < N; ++i) {
		if (A[i] <= K) {
			count = max(count, i + 1);
			for (int j = preJ; 0 <= j; --j) {
				if (A[i] + B[j] <= K) {
					count = max(count, i + j + 2);
					break;
				}
				else {
					preJ = j;
				}
			}
		}
		else {
			break;
		}
	}

	for (int i = 0; i < M; ++i) {
		if (B[i] <= K) {
			count = max(count, i + 1);
		}
		else {
			break;
		}
	}

	cout << count << endl;
	return 0;
}