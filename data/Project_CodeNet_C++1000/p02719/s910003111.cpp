#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fi first
#define sc second
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	ll n, k;
	scanf("%lld %lld", &n, &k);
	n %= k;
	
	ll ans = min(n, k - n);
	printf("%lld\n", ans);
}