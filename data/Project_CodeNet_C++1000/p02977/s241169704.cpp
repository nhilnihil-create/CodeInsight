//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
using namespace std;
const int N=2e5+5;
int n;
void solve(){
	puts("Yes");
	printf("%d %d\n",1,2),printf("%d %d\n",2,3),printf("%d %d\n",3,n+1),printf("%d %d\n",n+1,n+2),printf("%d %d\n",n+2,n+3);
	for(R int i=5;i<=n;i+=2){
		printf("%d %d\n",i-1,i),printf("%d %d\n",i,1),
		printf("%d %d\n",1,n+i-1),printf("%d %d\n",n+i-1,n+i);
	}
	if(n&1^1)printf("%d %d\n",n,n-1),printf("%d %d\n",n+(n^1^(n-1)),n+n);
}
int main(){
	scanf("%d",&n);
	if(n^(n&-n))return solve(),0;
	return puts("No"),0;
}