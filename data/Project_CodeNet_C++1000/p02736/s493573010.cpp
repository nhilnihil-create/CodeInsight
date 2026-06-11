#include<cstdio>
#include<iostream>
#include<algorithm>
 
using namespace std;
 
const int N = 1000005;
 
int n;
char s[N];
int t[N];
 
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) s[i]--;
	
	int sum=0,c=0;
	t[0]=t[1]=0;
	for(int i=2;i<=n;i++)
		if(i&1) t[i]=0;
		else t[i]=t[i/2]+1;
	for(int i=1;i<=n;i++){
		if(i>1) c+=t[n-i+1]-t[i-1];
		if(s[i]=='1' && c==0) sum^=1;
	}
	if(sum==1) { printf("1\n"); return 0; }
	
	for(int i=1;i<=n;i++)
		if(s[i]=='1') { printf("0\n"); return 0; }
	
	sum=0; c=0;
	for(int i=1;i<=n;i++){
		if(i>1) c+=t[n-i+1]-t[i-1];
		if(s[i]=='2' && c==0) sum^=1;
	}
	if(sum==1) printf("2\n");
	else printf("0\n");
	
	return 0;
}