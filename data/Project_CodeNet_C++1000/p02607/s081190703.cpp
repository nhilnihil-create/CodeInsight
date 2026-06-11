#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	int ans = 0;
	for(int i = 1; i <= N; i++)
	{
		int ai;
		scanf("%d", &ai);
		
		if(i % 2 == 1 && ai % 2 == 1)
			ans++;
	}
	
	printf("%d", ans);
}
