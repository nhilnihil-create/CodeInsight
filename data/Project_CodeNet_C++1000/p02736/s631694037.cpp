#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,a[N+5];char s[N+5];
int main()
{
	RI i;for(scanf("%d%s",&n,s),--n,i=0;i^n;++i) a[i]=abs(s[i]-s[i+1]);
	RI f=1;for(i=0;i^n;++i) if(a[i]==1) {f=0;break;}
	for(i=0;i^n;++i) a[i]==2&&(a[i]=f);
	RI ans=0;for(i=0;i^n;++i) (((n-1)^i)==(n-1)-i)&&(ans^=a[i]);
	return printf("%d",ans*(f+1)),0;
}