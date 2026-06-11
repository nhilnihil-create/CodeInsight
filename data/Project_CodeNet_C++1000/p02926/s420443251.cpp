#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N;
	double ANS = 0;
	pair<double, double> P[100], SUM[110] = {};
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
	sort(P, P + N, [](pair<double, double> P1, pair<double, double> P2) {return atan2l(P1.second, -P1.first) > atan2l(P2.second, -P2.first); });
	for (int i = 0; i < N; i++) {
		SUM[i + 1].first = SUM[i].first + P[i].first;
		SUM[i + 1].second = SUM[i].second + P[i].second;
	}
	for (int L = 1; L <= N; L++) {
		for (int R = 1; R <= N; R++) {
			if (L <= R) {
				double DX = SUM[R].first - SUM[L - 1].first;
				double DY = SUM[R].second - SUM[L - 1].second;
				ANS = max(ANS, sqrt(DX * DX + DY * DY));
			}
			else {
				double DX = SUM[N].first - (SUM[L - 1].first - SUM[R].first);
				double DY = SUM[N].second - (SUM[L - 1].second - SUM[R].second);
				ANS = max(ANS, sqrt(DX * DX + DY * DY));
			}
		}
	}
	printf("%.12lf\n", ANS);
}