#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	long long int Fraction = 1;
	for(int i = 0; i < n; i++){
		Fraction *= n-i;
	}
	printf("%lld\n", Fraction);
	return 0;
}