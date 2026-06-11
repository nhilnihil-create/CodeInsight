/*in the name of Allah the most beneficent the most merciful.*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
//#define mod2 20071027
//#define MOD 998244353
// #define base 100001
//#define mod 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case %lld:\n", ++c)
#define out(x) cout << #x << " -> " << x << endl;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
using namespace std;
const int N = 1000010;
ll n, a[N], pc = 1, g;
bool mp[N];
int solve() {
	in1(n);
	for (int i = 0; i < n; i++) {
		in1(a[i]);
		if (mp[a[i]] && a[i]>1) {
			pc = 0;
		}
		mp[a[i]] = 1;
		g = __gcd(g, a[i]);
	}
	if (g > 1) {
		printf("not coprime\n");
	}
	else {
		if (pc == 0) printf("setwise coprime\n");
		else {
			for (int i = 2; i <= 1000000; i++) {
				ll cnt = 0;
				for (ll j = i; j <= 1000000; j += i) {
					if (mp[j]) {
						cnt++;
					}
				}
				if (cnt > 1) {
					printf("setwise coprime\n");
					return 0;

				}
			}
			printf("pairwise coprime\n");
		}
	}

	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return solve();
}