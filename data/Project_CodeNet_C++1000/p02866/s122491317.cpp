#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;

const long MOD = 998244353;
int cnt[100003];
int A[100003];

int main()
{
	// freopen("input.in", "r", stdin);

	bool bol = 1;

	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{	
		int x; scanf("%d", &x);
		A[i] = x;
		if(i == 1 && x) bol = 0;
		if(i != 1 && x == 0) bol = 0;
		cnt[x]++;
	}
	if(!bol) printf("0\n");
	else
	{
		long res = 1;
		for(int i = 2; i <= n; i++)
			res = (res*cnt[A[i]-1])%MOD;

		printf("%lld\n", res);
	}
}