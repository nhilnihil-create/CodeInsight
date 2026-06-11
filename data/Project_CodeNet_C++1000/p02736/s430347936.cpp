#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int n; char s[1000010];
int pre[1000010],bin[1000010];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++) s[i]--;
	for(int i=0;i<=19;i++) bin[1<<i]=i;
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+bin[i&-i];
	bool mrk=0;
	for (int i=1;i<=n;i++) if (s[i]=='1') if (pre[n-1]-pre[i-1]-pre[n-i]==0) mrk^=1;
	if (mrk) return puts("1"),0;
	for (int i=1;i<=n;i++) if (s[i]=='1') return puts("0"),0;
	mrk=0;
	for (int i=1;i<=n;i++) if (s[i]=='2') if (pre[n-1]-pre[i-1]-pre[n-i]==0) mrk^=1;
	puts(mrk?"2":"0");
	return 0;
}