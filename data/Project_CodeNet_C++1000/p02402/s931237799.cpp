#include <stdio.h>
#define MAX 1000001
#define MIN -1000001
int main()
{
	//input
	int N,a_i,max=MIN,min=MAX;
	long long sum=0;
	scanf("%d",&N);
	//algorithm
	while(N--)
	{
		scanf("%d",&a_i);
		if(max<a_i) max=a_i;
		if(min>a_i) min=a_i;
		sum+=a_i;
	}
	//output
	printf("%d %d %lld\n",min,max,sum);
	return 0;
}
