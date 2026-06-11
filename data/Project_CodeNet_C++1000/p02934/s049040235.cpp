#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	int N;
	scanf("%d",&N);

	double ans = 0,tmp;

	for(int i = 0; i < N; i++){

		scanf("%lf",&tmp);

		ans += 1.0/tmp;
	}

	printf("%.10lf\n",1.0/ans);

	return 0;
}
