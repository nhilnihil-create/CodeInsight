#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <cstring>
#include <string>
#include <bitset>
#include <stdlib.h>
#include <time.h>  
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define st first
#define sd second
#define mkp make_pair
#define pb push_back
void wenjian(){freopen("xxx.in","r",stdin);freopen("xxx.out","w",stdout);}
void tempwj(){freopen("hash.in","r",stdin);freopen("hash.out","w",stdout);}
ll gcd(ll a,ll b){return b == 0 ? a : gcd(b,a % b);}
ll qpow(ll a,ll b,ll mod){a %= mod;ll ans = 1;while(b){if(b & 1)ans = ans * a % mod;a = a * a % mod;b >>= 1;}return ans;}
struct cmp{bool operator()(const pii & a, const pii & b){return a.second > b.second;}};
int lb(int x){return  x & -x;}

const double inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const int maxn = 2e5+5;
const int M = 1e8;

int a[maxn];
ll s[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	ll sum = 0;
	for (int i = 0; i<= n; i ++ )
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if(n > 0 && a[0] > 0)
	{
		printf("-1\n");
		return 0;
	}
	else if(n == 0 && a[0] > 1)
	{
		printf("-1\n");
		return 0;
	}
	ll s =  1;
	ll ans = 1;
	for (int i = 1; i <= n; i ++ )
	{
		s = min(s * 2, sum);
		ans += s;
		s -= a[i];
		sum -= a[i];
		// printf("%lld %lld %d\n",s,sum,a[i]);
		if(s < 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",ans);
}
