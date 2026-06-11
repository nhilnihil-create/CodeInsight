#include<bits/stdc++.h>
using namespace std;
char str[210][210];
int main()
{
	int n, m, kk;int ans = 0;
	scanf("%d%d%d", &n, &m, &kk);
	for(int i = 1; i <= n; i ++) scanf("%s", str[i] + 1);
	for(int i = 0; i <= (1 << n) - 1; i ++)
	{
		for(int j = 0; j <= (1 << m) - 1; j ++)
		{
			int cnt = 0;
			for(int x = 1; x <= n; x ++)
			{
				for(int y = 1; y <= m; y ++)
				{
					if(i & (1 << (x - 1)) || j & (1 << (y - 1))) continue;
					if(str[x][y] == '#') cnt ++;
				}
			}
			if(cnt == kk){
				ans ++;
				//cout <<i<<" "<<j<<"\n";
			} 
		}
	}
	printf("%d\n", ans);
	return 0;
} 