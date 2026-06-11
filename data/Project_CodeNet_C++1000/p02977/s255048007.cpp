#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=100000 +117;
const int MM=100000 +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}

void link(int x,int y){
	printf("%d %d\n",x,y);
}
int m,n;
int c[2]={};
int main(){
	//open();
	n=read();
	int x=n;
	while(!(x&1))x>>=1;
	if(x==1){
		printf("No\n");
		return 0;
	}
	else printf("Yes\n");
	int now=n^1;
	if(now&1){
		for(int i=2;i<n;++i){
			if((now^i)<n){
				c[0]=i,c[1]=now^i;
				break;
			}
		}
	}
	int top=n;
	if(n%2==0)--top;
	for(int i=2;i<=top;++i){
		link(i,1);
		link(i+n,i^1);
		if(c[0]==i)link(i,n);
		if(c[1]==i)link(i,n+n);
	}
	link(n+1,n+2);
	close();
	return 0;
}