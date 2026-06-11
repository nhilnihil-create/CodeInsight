#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int n,a,b,c,d,lst; char s[N]; bool flag;
int main()
{
	RI i; scanf("%d%d%d%d%d%s",&n,&a,&b,&c,&d,s+1);
	for (i=a;i<c;++i) if (s[i]=='#'&&s[i+1]=='#') return puts("No"),0;
	for (i=b;i<d;++i) if (s[i]=='#'&&s[i+1]=='#') return puts("No"),0;
	if (c<d) return puts("Yes"),0; for (flag=0,i=b;i<=d&&!flag;++i)
	if (s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.') flag=1;
	return puts(flag?"Yes":"No"),0;
}