#include<iostream>
#include<cstdio>
#define maxn 2000010
using namespace std;
int n,w,st=0;
int ans[2][10]={{0,1,0,1,1,2,1,0},{0,1,0,1,1,0,1,0}};
bool flag=0; 
char s[maxn];
int main(){
	scanf("%d%s",&n,s);
	n--;
	for(register int i=0;i<=n;i++){
		if(s[i]=='2')flag=1;
		w=s[i]-'1';
		st^=(1<<w)&((n==(n|i))?7:0);
	}
	printf("%d",ans[flag][st]);
	return 0;
} 