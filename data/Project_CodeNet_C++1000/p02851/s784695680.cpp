#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MAX_N = 200005;
ll A[MAX_N],S[MAX_N];
map<ll,ll> c;

int main()
{
	ll N,K;
	cin >> N >> K;
	rep(i,N)
	{
		cin >> A[i];
		A[i]--;
		S[i+1] = (S[i] + A[i]) % K;
	}
	ll ans = 0;
	for (ll j = 0; j <= N; ++j)
	{
		ans += c[S[j]];
		if (j >= K-1) c[S[j-K+1]]--;
		c[S[j]]++;
	}
	cout << ans << endl;
	return 0;
}