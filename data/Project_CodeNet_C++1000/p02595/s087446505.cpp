#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include<math.h>
#include <queue>
using namespace std;
#define Minf -1e9
#define scan(n) scanf("%lld",&n)
typedef long long ll;
const int maxn = 1*1e5+10;
const ll INF = 1e9+100;
const int mod = 998244353;

int a[maxn];
int main()
{
	ll n, k;
	scanf("%lld%lld", &n, &k);
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll x, y;
		scanf("%lld%lld", &x, &y);
		if (x*x+y*y <=(ll)k*k)ans++;
	}
	printf("%lld", ans);
}