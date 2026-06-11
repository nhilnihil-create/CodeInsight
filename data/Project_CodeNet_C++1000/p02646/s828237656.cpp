//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
int main()
{
	int a=read(),v=read(),b=read(),w=read(),t=read();
	if(1ll*t*(v-w)>=abs(b-a))	puts("YES"); else	puts("NO");	
	return 0;
}
