#include <iostream>
#include <cstdio>
#include <cmath>

#define pai 3.141592653

using namespace std;

int main(void)
{
	int n, s[1000];
	double sum, avg, a;
	int i;

	while(scanf("%d", &n)!=EOF && n!=0){
		sum = 0;
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
			sum += s[i];
		}
		avg = sum / n;

		sum = 0;
		for(i=0;i<n;i++)
			sum += pow(s[i] - avg, 2);
		a = sqrt(sum / n);

		printf("%.8f\n", a);
	}

	return 0;
}