#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009
int main(void){
	int n;
	double x[100];
	double y[100];
	double ans;
	scanf("%d", &n);
	f(i, n)scanf("%lf", &x[i]);
	f(i, n)scanf("%lf", &y[i]);
	ans = 0;
	f(i, n)ans += fabs(y[i] - x[i]);
	printf("%f\n", ans);
	ans = 0;
	f(i, n)ans += pow(y[i] - x[i], 2);
	printf("%f\n", sqrt(ans));
	ans = 0;
	f(i, n)ans += pow(fabs(y[i] - x[i]), 3);
	printf("%f\n", cbrt(ans));
	ans = 0;
	f(i, n)ans = max(ans, fabs(y[i] - x[i]));
	printf("%f\n", ans);

	return 0;
}