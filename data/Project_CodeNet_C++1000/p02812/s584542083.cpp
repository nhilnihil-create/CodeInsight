#include <bits/stdc++.h>
using namespace std;

void solve(long long N, std::string S)
{
	int count = 0;

	for (int i = 0; i < N - 2; i++)
	{
		string s = S.substr(i, 3);

		if (s == "ABC")
			count++;
	}

	cout << count << endl;
}

int main()
{
	long long N;
	scanf("%lld", &N);
	std::string S;
	std::cin >> S;
	solve(N, S);
	return 0;
}
