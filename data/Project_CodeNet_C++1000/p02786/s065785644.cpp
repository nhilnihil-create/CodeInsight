
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n)
{
	if(n == 1)
		return 1;
	else
		return  1LL + 2LL * solve(n/2);
}

int main()
{

	long long int n; cin >> n;
	cout << solve(n);

	return 0;
}