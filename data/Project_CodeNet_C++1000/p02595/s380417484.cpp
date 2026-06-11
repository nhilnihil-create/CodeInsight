#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int N, D;
	scanf("%lld%lld", &N, &D);
	
	int ans = 0;
	for(int i = 1; i <= N; i++)
	{
		long long int Xi, Yi;
		scanf("%lld%lld", &Xi, &Yi);
		
		if(Xi * Xi + Yi * Yi <= D * D)
			ans++;
	}
	
	printf("%d", ans);
}
