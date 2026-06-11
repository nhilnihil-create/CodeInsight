#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
int C[2005][2005];

void init(int n,int m)
{
	for(int i = 0;i <= n;++i)
	{
		C[i][0] = 1;
		for(int j = 1;j <= m && j <= i;++j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	
	ll ans = 0;
	int B=N / 3;
	init(2000,2000);
	for(int i = 1;i <= B;++i)
	{
		ans = (ans + C[N-2*i-1][i-1]) % mod;
	}
	return printf("%lld",ans),0;
} 