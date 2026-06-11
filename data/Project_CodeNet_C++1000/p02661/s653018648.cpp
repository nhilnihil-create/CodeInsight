#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[1 << 18], B[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	vector<int> V1, V2;
	for (int i = 1; i <= N; i++) V1.push_back(A[i]);
	for (int i = 1; i <= N; i++) V2.push_back(B[i]);
	sort(V1.begin(), V1.end());
	sort(V2.begin(), V2.end());

	int S1 = V1[N / 2]; if (N % 2 == 0) S1 = V1[N / 2] + V1[(N - 2) / 2];
	int S2 = V2[N / 2]; if (N % 2 == 0) S2 = V2[N / 2] + V2[(N - 2) / 2];
	cout << S2 - S1 + 1 << endl;
	return 0;
}