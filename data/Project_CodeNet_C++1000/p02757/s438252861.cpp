#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 200005;
ll U[MAX_N],cnt[MAX_N],pow10[MAX_N];

/*
ll modpow(ll a, ll p)
{
	if (p == 0) return ll(1);
	if (p == 1) return a%p;
	if (p % 2 == 0)
	{
		ll b = modpow(a,p/2);
		return b * b % p;
	}
	else
	{
		return p * modpow(a,p-1) % p;
	}
}
*/

int main()
{
	ll N,P;
	cin >> N >> P;
	string S;
	cin >> S;

	pow10[0] = 1;
	rep(i,MAX_N-1)
	{
		pow10[i+1] = pow10[i] * 10 % P;
	}
	U[N] = 0;
	cnt[0] = 1;
	ll ans = 0;
	if (P == 2 || P == 5)
	{
		rep(i,N)
		{
			if ((S[i] - '0') % P == 0)
			{
				ans += i+1;
			}
		}
	}
	else
	{
		rep(i,N)
		{
			U[N-1-i] = ((S[N-1-i] - '0') * pow10[i] + U[N-i]) % P;
			ans += cnt[U[N-1-i]];
			cnt[U[N-1-i]]++;
		}
	}
	cout << ans << endl;
	return 0;
}