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
	double x[1000];
	double m,ans;
	for (;;){
		m = 0;
		ans = 0;
		scanf("%d", &n);
		if (n == 0)break;
		f(i, n){
			scanf("%lf", &x[i]);
			m += x[i];
		}
		m = m / n;
		f(i, n){
			ans += (x[i] - m)*(x[i] - m);
		}
		ans = ans / n;
		printf("%f\n", sqrt(ans));
	}
	return 0;
}