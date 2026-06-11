#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;

int A[N];

int main()
{
	int n; scanf("%d",&n);
	int mx = 0;
	ll res = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &A[i]);
		res += max(mx - A[i], 0);
		mx = max(mx, A[i]);
	}


	printf("%lld\n", res);
}
