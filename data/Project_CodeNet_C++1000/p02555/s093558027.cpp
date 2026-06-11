#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
int f[2005][2005];

int main()
{
	int N;
	scanf("%d",&N);
	
	ll ans = 0;
	f[0][0] = 1;
	int B = N / 3;
	for(int i = 1;i <= B;++i)
		for(int j = 3;j <= N;++j)
		{
			f[i][j] = (f[i][j-1] + f[i-1][j-3]) % mod;
			if(j == N) ans = (ans + f[i][j]) % mod;
		}	
	return printf("%lld",ans),0;
}