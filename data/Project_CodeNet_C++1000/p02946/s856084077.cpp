#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){


	int K,X;
	scanf("%d %d",&K,&X);

	printf("%d",X-K+1);
	for(int i = X-K+2; i <= X+K-1; i++){

		printf(" %d",i);
	}
	printf("\n");

	return 0;
}
