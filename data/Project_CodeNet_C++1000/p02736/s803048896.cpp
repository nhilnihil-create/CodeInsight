
#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
long get2power(long n) {
	long result = 0;
	while (n % 2 == 0) {
		n = n / 2;
		result++;
	}
	return result;
}
int main()
{
	long N;
	string s;
	cin >> N >> s;
	vector<long> next(N);
	long ans = 0;
	int two = 2;
	for (int i = 0; i < N; i++)
	{
		next[i] = s[i] - '0' - 1;//abs((s[i] - '0') - (s[i+1] - '0'));
		if (s[i] - '0' - 1 == 1)
		{
			two = 1;
		}
	}
	long p = 0, n = 0;
	for (int i = 0; i < N - 1; i++)
	{
		next[i] = (p == n) ? next[i] : 0;
		p += get2power(N - 1 - i);
		n += get2power(i + 1);
	}
	next[N - 1] = (p == n) ? next[N - 1] : 0;

	for (int i = 0; i < N; i++)
	{
		ans += (two == 2) ? next[i] / 2 : next[i] % 2;// abs(ans - next[i]);
	}

	cout << (ans % 2) * two;;
	return 0;
}
