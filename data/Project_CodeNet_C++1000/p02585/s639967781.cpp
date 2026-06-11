#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 987654321987654321;

int main()
{
	int N, K;
	ll ans = -INF;
	cin >> N >> K;
	vector<int>P(N), C(N);
	for (auto&i : P)
	{
		cin >> i;
		i--;
	}
	for (auto&i : C)cin >> i;

	for (int i = 0; i < N; i++)
	{
		int cycleN = 1, now = P[i];
		ll cycleSum = C[i];
		while (now != i)
		{
			cycleN += 1;
			cycleSum += C[now];
			now = P[now];
		}
		ll path = 0;
		int cnt = 0;
		while (true)
		{
			cnt++;
			path += C[now];
			if (cnt > K)break;
			ll score = path + max((ll)0, cycleSum)*((K - cnt) / cycleN);
			ans = max(ans, score);
			now = P[now];
			if (now == i)break;
		}
	}
	cout << ans;
}
