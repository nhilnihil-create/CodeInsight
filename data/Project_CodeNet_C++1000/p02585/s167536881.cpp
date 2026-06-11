#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

/*
n <= 5000なので必ず5000ステップ以内にループができる
ある場所から始めた時に、5000回やってどこかでループが出てくる
ループが出てきた時に、1ループで収支がプラスなら最大のループ数-1回ループをして、二回回って最大を見れば良さそう
5000 * 5000 * 3? = 7.5 * 10^7だから多分いける

piが全て異なるということから一個の輪になる
このことから1ループはciの総和
*/

int	main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	long long ans = c[0];
	for (int start = 1; start <= n; start++)
	{
		int now = start;
		long long tmp = 0;
		int loop_cnt = 0;
		long long loop_value = 0;
		for (int i = 0; i < n; i++)
		{
			now = p[now - 1];
			loop_cnt++;
			loop_value += c[now - 1];
			if (now == start) break ;
		}
		int k2 = k;
		if (k2 / loop_cnt >= 2 && loop_value > 0)
		{
			tmp += (k2 / loop_cnt - 2) * loop_value;
			k2 -= loop_cnt * (k2 / loop_cnt - 2);
		}
		else if (k2 / loop_cnt >= 2) k2 -= loop_cnt * (k2 / loop_cnt - 2);
		for (int i = 0; i < k2; i++)
		{
			now = p[now - 1];
			tmp += c[now - 1];
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	return (0);
}
