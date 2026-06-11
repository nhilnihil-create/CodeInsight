#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int n;
int main(){
	n=read();
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			printf("%d ",__builtin_ffs(i^j));
		}
		printf("\n");
	}
	return 0;
}
