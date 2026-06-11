#include<cstdio>
#include<algorithm>
using namespace std;
void link(int x,int y){
	printf("%d %d\n",x,y);
}
int main(){
	int n;
	scanf("%d",&n);
	if((1<<__builtin_ctz(n))==n)
		return puts("No"),0;
	puts("Yes");link(1,n+2);
	for(int i=2;i<n;i+=2)
		link(1+n,i),link(i,i+1),link(1+n,i+1+n),link(i+1+n,i+n);
	if(~n&1){
		int m=n&-n;
		link(n,n+m+1);link(n+n,n-m);
	}
	return 0;
}
