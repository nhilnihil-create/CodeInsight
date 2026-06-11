#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

char s[MAXN];
int a[MAXN];

int c(int n,int m){ return (n|m)==n;}

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i) a[i]=s[i]-'1';
	
	bool flag=1;
	for(int i=1; i<=n; ++i)
		if(a[i]==1){ flag=0; break;}
	
	if(flag)
	{
		for(int i=1; i<=n; ++i)
			a[i]>>=1;
	}
	else
	{
		for(int i=1; i<=n; ++i)
			a[i]&=1;
	}
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		ans ^= a[i]&c(n-1,i-1);
	if(flag) ans<<=1;
	printf("%d",ans);
	return 0;
}