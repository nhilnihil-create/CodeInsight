#include <iostream>
#include <cmath>
using namespace std;
int n,k,tmp,ans;
char s[100010];
int main()
{
	scanf("%d%d",&n,&k);
	getchar();
	for(int i = 1;i <= n;i ++)
	{
		s[i] = getchar();
		if(s[i] == s[i - 1])
			tmp ++;
	}
	ans = min(tmp + 2 * k,n - 1);
	printf("%d\n",ans);
	return 0;
}