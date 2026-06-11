#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline void p(int x,int y){
	printf("%d %d\n",x,y);
}
int main(){
	int n;
	scanf("%d",&n);
	int u=1;
	while(u<=n){
		if(u==n){puts("No"); return 0;}
		u<<=1;
	}
	puts("Yes");
	p(1,2);
	p(2,3);
	p(3,n+1);
	p(n+1,n+2);
	p(n+2,n+3);
	if(n&1){
		for(int i=4;i<=n;i+=2){
			p(i,i+1);
			p(i+1,1);
			p(1,n+i);
			p(n+i,n+i+1);
		}
	}else{
		for(int i=4;i<n;i+=2)if(i!=(n^(n&-n))){
			p(i,i+1);
			p(i+1,1);
			p(1,n+i);
			p(n+i,n+i+1);
		}else{
			p(i,(n&-n));
			p(i+1,i);
			p((n&-n)+1,n+i+1);
			p(n+i,n+i+1);
		}
		p(n,(n&-n));
		p(n+n,n^(n&-n));
	}
	return 0;
}