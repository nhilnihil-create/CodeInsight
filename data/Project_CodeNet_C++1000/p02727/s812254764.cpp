#include <iostream>
#include <algorithm>
using namespace std;

int X, Y, A, B, C;
int P[1 << 18];
int Q[1 << 18];
int R[1 << 18];

int main() {
	cin >> X >> Y >> A >> B >> C;
	for (int i = 0; i < A; i++) cin >> P[i];
	for (int i = 0; i < B; i++) cin >> Q[i];
	for (int i = 0; i < C; i++) cin >> R[i];
	sort(P, P + A); reverse(P, P + A);
	sort(Q, Q + B); reverse(Q, Q + B);
	for (int i = 0; i < X; i++) R[C + i] = P[i];
	for (int i = 0; i < Y; i++) R[C + X + i] = Q[i];
	sort(R, R + C + X + Y);
	reverse(R, R + C + X + Y);

	long long score = 0;
	for (int i = 0; i < X + Y; i++) score += R[i];
	cout << score << endl;
	return 0;
}