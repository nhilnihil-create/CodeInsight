#include<cstdio>
using namespace std;
char s[100005];
int main(){
	int n,k,ans,ls=1;
	char x,xx='A';
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]) ls++;
	}
	if(ls-2*k<=1) ans=n-1;
	else ans=n-(ls-2*k);
	printf("%d",ans);
	return 0;
}