#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 1e9+7;

ll pow(int x, int n) //x^n
{
	if (n == 0) return ll(1);
	if (n == 1) return ll(x);
	if (n % 2 == 1)
	{
		return x * pow(x,n-1) % MOD;
	}
	else
	{
		ll p = pow(x,n/2);
		return p * p % MOD;
	}
}

int main()
{
	string L;
	cin >> L;
	int N = L.size();
	ll ans = 0;
	int cnt = 0;
	rep(i,N)
	{
		if (L[i] == '1')
		{
			ans = (ans + pow(3,N-i-1) * pow(2,cnt)) % MOD;
			cnt++;
		}
	}
	ans = (ans + pow(2,cnt)) % MOD;
	cout << ans << endl;
	return 0;
}