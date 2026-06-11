#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int maxn=1e6+5;

int n,a[maxn];
char s[maxn];

bool calc()
{
	bool re=0;
	fo(i,0,n) if (a[i]&1)
	{
		bool pd=1;
		for(int nn=n, ii=i; nn; nn>>=1, ii>>=1) if (!(nn&1) && (ii&1)) {pd=0; break;}
		re^=pd;
	}
	return re;
}

int main()
{
	scanf("%d",&n); n--;
	scanf("%s",s);
	bool one=0;
	fo(i,0,n)
	{
		a[i]=s[i]-'1';
		one|=(a[i]&1);
	}
	
	if (calc()) {puts("1"); return 0;}
	if (one) {puts("0"); return 0;}
	fo(i,0,n) if (a[i]==2) a[i]--;
	printf("%d\n",calc()<<1);
}