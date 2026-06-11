#include<cstdio>
#include<cstring>
using namespace std;
int l1,l2,ans;
char s[1005],t[1005];
int main()
{
	scanf("%s\n",s+1);
	scanf("%s",t+1);
	l1=strlen(s+1),l2=strlen(t+1);
	ans=l2;
	for (int i=1;i<=l1-l2+1;i++)
	{
		int ans1=0;
		for (int j=i;j<i+l2;j++)
		if (s[j]!=t[j-i+1]) ans1++;
		ans=ans<ans1?ans:ans1; 
	}
	printf("%d",ans);
	return 0;
} 