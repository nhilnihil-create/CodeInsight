#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,ans;
int a[N];
char str[N];
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	for (register int i=1; i<=n; ++i) a[i]=str[i]-'0';
	for (register int i=n; i>=0; --i)
	{
		if (a[i]>5) a[i-1]++,ans+=10-a[i];
		else if (a[i]<5) ans+=a[i];
		else
		{
			ans+=5;
			if (a[i-1]>=5) a[i-1]++; 
		}
	}
	printf("%d\n",ans);
return 0;
}