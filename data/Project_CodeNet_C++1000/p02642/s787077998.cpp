#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include<set>
using namespace std;

int main()
{
	const int M = 1000005;
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<int> cnt(M);
	for (int i = 0; i < N; ++i)
	{
		if (cnt[a[i]] != 0)
		{
			cnt[a[i]] = 2;
			continue;
		}
		for (int j = a[i]; j < M; j += a[i]) cnt[j]++;
	}

	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		if (cnt[a[i]] == 1) ans++;
	}
	cout << ans << endl;
}