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
	double x1, x2, y1, y2, ans;
	ans = 0;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	ans = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
	ans = sqrt(ans);
	printf("%f\n", ans);
	return 0;
}