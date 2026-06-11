#include<bits/stdc++.h>
#define poi 201000
using namespace std;
typedef long long ll;

inline int re()
{
	char x=getchar();
	int k=1,y=0;
	while(x<'0'||x>'9')
	{if(x=='-') k=-1;x=getchar();}
	while(x>='0'&&x<='9')
	{y=(y<<3)+(y<<1)+x-'0';x=getchar();}
	return y*k;
}
void wr(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
signed main()
{
	//freopen("lca.in","r",stdin);
	//freopen("lca.out","w",stdout);
	int x=re();
	for(int i=1;;i++)
	{
		if(!((360*i)%x))
		{
			wr((360*i)/x);
			break;
		}
	}
	return 0;
}