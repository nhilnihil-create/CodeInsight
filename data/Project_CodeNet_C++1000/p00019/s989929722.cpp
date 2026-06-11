#include <cstdio>
using namespace std;

int main()
{
	int n;
	long ans = 1;
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++){
		ans *= i;
	}
	
	printf("%ld\n", ans);
	
	return (0);
}