#include <stdio.h>
int main(){
	long long sum;
	int min,max,a[10000],n,cnt;
	scanf("%d",&n);
	for(cnt=0;cnt<n;cnt++){
		scanf("%d",&a[cnt]);
		if(cnt==0){
			min=a[cnt];
			max=a[cnt];
		}
		else if(a[cnt]>max){
			max=a[cnt];
		}
		else if(a[cnt]<min){
			min=a[cnt];
		}
		sum+=a[cnt];
	}
	printf("%d %d %lld\n",min,max,sum);
	return 0;
}