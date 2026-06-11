#include<iostream>
#include<vector>
using namespace std;
const int MAX = 100005;

int main() {
	int N;
	cin >> N;
	vector<int> A(MAX);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		A[x]++;
	}

	int Q;
	cin >> Q;
	long long ans = 0;
	for (int i = 0; i < MAX; i++) {
		ans += (long long)i * A[i];
	}

	for (int i = 0; i < Q; i++) {
		int B, C;
		cin >> B >> C;
		ans += ((long long)C - B) * A[B];
		A[C] += A[B];
		A[B] = 0;
		cout << ans << endl;
	}

	return 0;
}