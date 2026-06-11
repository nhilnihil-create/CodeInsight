#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using LL = long long;

int main() {
	LL A, B, C, X, Y;
	cin >> X >> Y >> A >> B >> C ;
	vector<LL> P(A), Q(B), R(C);
	for (int i = 0; i < A; i++) {
		cin >> P[i];
	}
	for (int i = 0; i < B; i++) {
		cin >> Q[i];
	}
	for (int i = 0; i < C; i++) {
		cin >> R[i];
	}
	sort(P.begin(), P.end(), std::greater<LL>());
	sort(Q.begin(), Q.end(), std::greater<LL>());
	sort(R.begin(), R.end(), std::greater<LL>());

	// 赤色X個食べたとき
	LL sum_A = 0;
	LL A_num = X;
	LL sum_B = 0;
	LL B_num = Y;
	LL C_num = 0;
	while (true) {
		if (P[A_num - 1] <= Q[B_num - 1] && P[A_num - 1] < R[C_num]) {
			A_num--;
			C_num++;
		}
		else if (P[A_num - 1] > Q[B_num - 1] && Q[B_num - 1] < R[C_num]) {
			B_num--;
			C_num++;
		}
		else if (min(P[A_num - 1], Q[B_num - 1]) >= R[C_num]) {
			break;
		}
		if (A_num == 0 || B_num == 0 || C_num >= C) {
			break;
		}
	}
	// 赤だけ(B枯渇)
	while (C_num < C && A_num != 0) {
		if (P[A_num - 1] < R[C_num]) {
			A_num--;
			C_num++;
		}
		else if (P[A_num - 1] >= R[C_num]) {
			break;
		}
	}

	while (C_num < C && B_num != 0) {
		if (Q[B_num - 1] < R[C_num]) {
			B_num--;
			C_num++;
		}
		else if (Q[B_num - 1] >= R[C_num]) {
			break;
		}
	}


	LL ans = 0;
	for (int i = 0; i < A_num; i++) {
		ans += P[i];
	}
	for (int j = 0; j < B_num; j++) {
		ans += Q[j];
	}	
	for (int i = 0; i < C_num; i++) {
		ans += R[i];
	}
	cout << ans << endl;
	return 0;
}