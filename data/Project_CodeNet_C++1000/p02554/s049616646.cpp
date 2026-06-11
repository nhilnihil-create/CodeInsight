#include <cstdio>
#include <cstring>
#include <cmath>
#include<algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


int main()
{
	long long int n,a,b,c;
	a = 1;
	b = 1;
	c = 1;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		a =(a* 10) % (1000000000 + 7);
		b =(b* 9) % (1000000000 + 7);
		c =(c*8) % (1000000000 + 7);
	}
	b =(b* 2) % (1000000000 + 7);
	long long int sum = (a - b + c + (1000000000 + 7)) % (1000000000 + 7);
	
	printf("%lld", sum);
	
}