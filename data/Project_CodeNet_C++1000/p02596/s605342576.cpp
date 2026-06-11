#include <stdio.h>
int main(){
	int k,cnt,a;
	scanf("%d",&k);
	if(k%2==0||k%10==5){printf("-1\n");return 0;}//偶数找不到对应的777...7，个位是5的k找不到对应的777...7,需特判
	a=7,cnt=1;//cnt统计7出现的个数
	while(1){//特殊的高精度除
		if(a%k==0)break;
		a%=k,a=a*10+7,cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
 