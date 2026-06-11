#include<cstdio>
#include<algorithm>
using namespace std;
int a[1110000];
long long cnt[1110000],ans[1110000];
bool cmp(int a,int b)
{return a>b;}
inline void read(int &x)
{
	x=0;register char c=getchar();
	while(c<48||57<c)c=getchar();
	for(;48<=c&&c<=57;c=getchar()) x=x*10+(c&15);
}
void write(const int x)
{
	if(x>9)write(x/10);
	putchar(x%10|48);
}
int main()
{
	int n;
	read(n);
	int x;
	for(int i=1;i<=n;i++)
	{
		read(x);
		a[x]++;
	}
	//a:the number of the xs
	int len;
	for(int i=1;i<=n;i++)
		cnt[a[i]]++;
	len--;
	//cnt:the number of the as
	
	for(int i=n;i;i--)
		cnt[i]+=cnt[i+1];
	int Ans=0;
	long long Cnt=0;
	for(int i=n;i;i--)
	{
		while((Cnt+cnt[Ans+1])>=1ll*i*(Ans+1))
			Cnt+=cnt[++Ans];
		ans[i]=Ans;
	}
	for(int i=1;i<=n;i++)
		write(ans[i]),putchar(10);
	return 0;
}