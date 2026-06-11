#include<iostream>
#include<cstdio>
#include<cstring>
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
int m,d,ans;
int main(){
	m=read(),d=read();
	for(int i=4;i<=m;++i){
		for(int j=22;j<=d;++j){
			int x=j%10,y=j/10;
			if(x>=2&&y>=2&&x*y==i)++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
