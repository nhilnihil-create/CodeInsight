#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
const ll INF = 1e18;
ll A[MAX_N],L[MAX_N],R[MAX_N];

int main()
{
	int N;
	cin >> N;
	rep(i,N+1)
	{
		cin >> A[i];
	}

	L[N] = A[N];
	R[N] = A[N];
	for (int i = N-1; i >= 0; --i)
	{
		L[i] = A[i] + (L[i+1]+1) / 2;
		R[i] = A[i] + R[i+1];
	}
	if (L[0] > 1)
	{
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	ll temp = 1;
	rep(i,N+1)
	{
		ans += temp;
		temp -= A[i];
		temp = min(temp*2,R[i+1]);
	}
	cout << ans << endl;
	return 0;
}