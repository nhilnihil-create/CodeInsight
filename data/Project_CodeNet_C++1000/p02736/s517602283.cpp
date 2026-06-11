#include<iostream>
#include<cstdio>
#define maxn 2000010
using namespace std;
int n,tot=0,st=0;
int a[maxn],q1[maxn],q2[maxn],cnt[maxn];
int ans[2][10]={{0,1,0,1,1,2,1,0},{0,1,0,1,1,0,1,0}};
char s[maxn];
void solve(int l,int r,int now){
	int len=(q1[now]-q2[now-1])%q1[now];
	if(!len){
		for(register int i=l;i<=r;i++){
			st^=(1<<a[i]);
		}
	}
	else{
		int res=(r-l+1-len)>>1;
		solve(l,l+res-1,now-1);
		solve(r-res+1,r,now-1);
	}
}
int main(){
	scanf("%d%s",&n,s+1);
	bool flag=0; 
	for(register int i=1;i<=n;i++){
		if(s[i]=='2')flag=1;
		a[i]=s[i]-'1';
	}
	for(register int i=n,j=1,k=0;i;i>>=1,j<<=1){
		if(i&1){
			q1[++tot]=j;
			k+=j;
			q2[tot]=k;
		}
	}
	solve(1,n,tot);
	printf("%d",ans[flag][st]);
	return 0;
} 