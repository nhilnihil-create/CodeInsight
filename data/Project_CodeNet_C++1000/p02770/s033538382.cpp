#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[5010];
ll b[5010];
int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < m; i++) {
		ll q, w, e;
		scanf("%lld %lld %lld", &q, &w, &e);
		ll ans = q - 1;
		for (int y = 0; y < n; y++) {
			b[y] = a[y] % e;
		}
		w %= e;
		ll sum = 0;
		ll zersum = 0;
		for (int y = 0; y < n; y++) {
			sum += b[y];
			if (!b[y])zersum++;
		}
		q--;
		zersum = zersum * (q / n);
		sum = sum * (q / n);
		for (int y = 0; y < q % n; y++) {
			sum += b[y];
			if (!b[y])zersum++;
		}
		sum += w;
		ans -= zersum;
		ans -= (sum / e);
		printf("%lld\n", ans);
	}
}