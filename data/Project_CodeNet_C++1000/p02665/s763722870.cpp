#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<long> v(N + 1);
	for (int i = 0; i <= N; ++i)
		cin >> v[i];
	vector<unsigned long long int> back(N + 1);
	vector<unsigned long long int> minimum(N + 1);

	back[N] = v[N];
	minimum[N] = v[N];
	for (int i = N - 1; i >= 0; --i)
	{
		back[i] = back[i + 1] + v[i];
		minimum[i] = (minimum[i + 1] + 1) / 2 + v[i];
	}
	unsigned long  long int  ans = 1, remain = 1;
	bool flag = false;
	if (v[0] == 1 && N > 0 || (v[0]!=1 && N==0))
	{
		cout << "-1" << endl;
		return 0;
	}

	for (int i = 1; i <= N; ++i)
	{
		remain *= 2;
		if (minimum[i] > remain)
		{
			flag = true;
			break;
		}
		remain = min(remain, back[i]);
		ans += remain;
		remain -= v[i];
	}
	if (flag)
	{
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}