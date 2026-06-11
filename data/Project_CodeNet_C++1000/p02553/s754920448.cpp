#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

	long long  a,arr[4],b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	arr[0] = a*c;
	arr[1] = a*d;
	arr[2] = b*c;
	arr[3] = b*d;
	sort(arr,arr+4);
	printf("%lld\n",arr[3]);
	return 0;
}
