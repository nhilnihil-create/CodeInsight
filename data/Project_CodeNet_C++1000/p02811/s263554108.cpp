#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long K, long long X)
{
	if (K * 500 >= X)
		cout << "Yes" << endl;
	else
		cout << NO << endl;
}

int main()
{
	long long K;
	scanf("%lld", &K);
	long long X;
	scanf("%lld", &X);
	solve(K, X);
	return 0;
}
