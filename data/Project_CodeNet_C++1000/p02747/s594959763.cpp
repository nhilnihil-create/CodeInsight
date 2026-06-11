#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 23
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
char s[N];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n&1)return !printf("No\n");
	for(int i=1;i<=n;i+=2){
		if(s[i]!='h')return !printf("No\n");
	}
	for(int i=2;i<=n;i+=2){
		if(s[i]!='i')return !printf("No\n");
	}
	printf("Yes\n");
	return 0;
}

