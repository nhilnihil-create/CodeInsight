#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200000
#define MOD 1000000007
int n,ans,tp;
char s[MAXN+1];
char stk[MAXN+1];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=1;
	if(s[1]=='W'){
		printf("0\n");return 0;
	}
	stk[++tp]='B';stk[0]='W';
	for(int i=2;i<=2*n;i++){
		if(stk[tp]==s[i]){
	       ans=(1LL*ans*tp)%MOD,tp--;
		}
	    else stk[++tp]=s[i];
	    if(tp<0){printf("0");return 0;}
	}
	for(int i=1;i<=n;i++)
	ans=(1LL*ans*i)%MOD;
	if(!tp)printf("%d",ans);
	else printf("0");
}