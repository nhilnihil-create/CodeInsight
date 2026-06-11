#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],p,vis[3];
char s[1000005];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<n;i++) a[i]=abs(s[i]-s[i+1]),vis[a[i]]=1;
	if(!vis[1]) for(int i=1;i<n;i++) a[i]/=2;
	else for(int i=1;i<n;i++) a[i]%=2;
	int S=n-2;
	for(int i=0;i<n-1;i++) if((S&i)==i) p+=a[i+1];
	int op=p%2;
	if(!vis[1]) if(op) op=2;
	printf("%d\n",op);

	return 0;
}