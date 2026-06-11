#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int A, B, M;
int P[1 << 18], Q[1 << 18];
int X[1 << 18], Y[1 << 18], Z[1 << 18];

int main() {
	cin >> A >> B >> M;
	for (int i = 1; i <= A; i++) cin >> P[i];
	for (int i = 1; i <= B; i++) cin >> Q[i];

	int Answer = (1 << 30);
	for (int i = 1; i <= M; i++) {
		cin >> X[i] >> Y[i] >> Z[i];
		Answer = min(Answer, P[X[i]] + Q[Y[i]] - Z[i]);
	}
	int minp = (1 << 30), minq = (1 << 30);
	for (int i = 1; i <= A; i++) minp = min(minp, P[i]);
	for (int i = 1; i <= B; i++) minq = min(minq, Q[i]);
	Answer = min(Answer, minp + minq);

	cout << Answer << endl;
	return 0;
}