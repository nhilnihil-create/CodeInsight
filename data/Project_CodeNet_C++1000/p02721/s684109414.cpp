#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,c,len,tot;
int l[N],r[N];
char str[N];
int main(){
	scanf("%d%d%d",&n,&k,&c);
	scanf("%s",str+1);
	len=strlen(str+1);
	int i=1;
	while (i<=len)
	{
		if (tot==k) break;
		if (str[i]=='o') l[++tot]=i,i+=c+1;
		else i++;
	}
	i=len;
	tot=0;
	while (i>=1)
	{
		if (tot==k) break;
		if (str[i]=='o') r[++tot]=i,i-=c+1;
		else i--;
	}
	reverse(r+1,r+tot+1);
	for (register int i=1; i<=tot; ++i) if (l[i]==r[i]) printf("%d\n",l[i]);
return 0;
}