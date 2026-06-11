#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1000005;

int n;
char str[MAXN];
int a[MAXN];

int main()
{
	bool h1=0;
	int res=0;
	readint(n);
	scanf("%s",str+1);
	for(int i=1;i<=n;++i)
	{
		a[i]=str[i]-'0'-1;
		if(a[i]==1)h1=1;
		bool flag=1;
		for(int j=0;(1<<j)<=n;++j)
			if(!((n-1)&(1<<j)) && ((i-1)&(1<<j)))
				{flag=0;break;}
		if(flag)res^=a[i];
	}
	if(res&1)printf("1\n");
	else if(h1)printf("0\n");
	else printf("%d\n",res);
	return 0;
}