#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main() {
	int x, y, z;
	int s, ans;
	scanf("%d %d", &x, &y);
	ans = max(0, (4 - x) * 100000);
	ans += max(0, (4 - y) * 100000);
	if ((x + y) == 2)ans += 400000;
	printf("%d\n", ans);


	return 0;
}
