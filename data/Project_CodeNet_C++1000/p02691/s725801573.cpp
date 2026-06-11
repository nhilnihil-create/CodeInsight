#include <algorithm>
#include <cstdio>
#define INF 1e9
#define eps 1e-6
typedef long long ll;
using namespace std;

int n;
ll a[200010], A[200010], B[200010], l, r, ans;

int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		A[i] = a[i] + i;
		B[i] = a[i] - i;
	}
	sort(B + 1, B + n + 1);
	for(int i = 1; i <= n; i++){
		l = lower_bound(B + 1, B + n + 1, -A[i]) - B;
		r = upper_bound(B + 1, B + n + 1, -A[i]) - B;
		ans += r - l;
	}
	printf("%lld\n", ans);

	return 0;
}
