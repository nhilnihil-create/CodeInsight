#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	while(true){
		int n,m,p,all=0,y=-1;
		scanf("%d%d%d",&n,&m,&p);
		if(n==0) break;
		rep(i,n){
			int x;
			scanf("%d",&x);
			if(i+1==m) y=x;
			all+=x*100;
		}
		if(y==0){
			printf("0\n");
			continue;
		}
		printf("%d\n",all*(100-p)/100/y);
	}
	return 0;
}