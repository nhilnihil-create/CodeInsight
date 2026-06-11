// contest.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "bits/stdc++.h"
using namespace std;
int main()
{
	long N, M, V, P;
	cin >> N >> M >> V >> P;
	vector<long> A(N);
	for (auto& x : A)
	{
		cin >> x;
	}
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());

	long h = 1;
	while (h < N) {
		h *= 2;
	}
	long t = h / 2;
	long step = h / 2;
	while (step > 0)
	{
		if (t >= N) {
			step = step / 2;
			if (step == 0) {
				t--;
				break;
			}
			t -= step;
			continue;
		}
		long voted = N - t + P - 1;
		long box = 0;
		long flg = 1;
		for (int i = t - 1; i >= P - 1; i--)
		{
			box += A[t] + M - A[i];
			if (A[t] + M - A[i] < 0)
			{
				flg = -1;
				break;
			}
		}
		voted = N - t + P - 1 + box / M;
		step = step / 2;
		if (voted >= V && flg==1)
		{
			t += step;
		}
		else
		{
			if (step == 0) {
				t--;
				break;
			}
			t -= step;
		}
	}
	cout << t + 1;
	return 0;
}
