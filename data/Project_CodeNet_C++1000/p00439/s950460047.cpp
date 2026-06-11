#include <stdio.h>

int main()
{
	int max,a[100000],sum,k,n;

	
	while(scanf("%d %d",&n,&k) && n || k ){
	
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
	
		sum = 0;
		for(int i = 0; i < k; i++){
			sum += a[i];
		}
	
		max = sum;
		for(int i = k; i < n; i++){
			sum += a[i]-a[i-k];
			if(sum > max){
				max = sum;
			}
		}

		printf("%d\n",max);
	}

	return 0;
}