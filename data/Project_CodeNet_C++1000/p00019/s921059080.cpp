#include <cstdio>
using namespace std;

int main(void)
{
	int n;
	long long sum = 1;

	scanf("%d",&n);
	for(int f1 = 1; f1 <= n; f1++){
		sum *= f1;
	}

	printf("%lld\n", sum);
	return 0;
}