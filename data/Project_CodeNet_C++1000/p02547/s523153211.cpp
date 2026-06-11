#include<cstdio>
using namespace std;
int main(){
	bool bj=0;
	int n,x,y,sum=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		if (x==y) ++sum;
		else sum=0;
		if (sum==3) bj=1;
	}
	if (bj) puts("Yes");
	else puts("No");
	return 0;
}