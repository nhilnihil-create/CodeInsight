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
char ch[22]; 
int main()
{
	scanf("%s",ch+1); printf("%c%c%c\n",ch[1],ch[2],ch[3]);
	return 0;
}
