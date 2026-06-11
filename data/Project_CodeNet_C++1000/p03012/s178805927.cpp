#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,w[1005],sum1[105],sum2[105],minn=0x7fffffff;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",w+i);
		sum1[i]=sum1[i-1]+w[i];
	}
	for(int i=n;i>=0;--i){
		sum2[i]=sum2[i+1]+w[i];
		minn=min(abs(sum2[i+1]-sum1[i]),minn);
	}
	printf("%d\n",minn);
	return 0;
}
