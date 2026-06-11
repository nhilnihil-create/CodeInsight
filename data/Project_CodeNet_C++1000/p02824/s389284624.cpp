#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 100100;
int n;
ll m, v, p;
ll a[N];
ll pref[N];
 
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	scanf("%d%lld%lld%lld", &n, &m, &v, &p);
	int ans = 0;
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	reverse(a, a + n); // 将初始分数排序
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + a[i]; // 前缀和计算区间分数和
	ans = p;
	for (int i = p; i < n; i++) {
		if (a[i] + m < a[p - 1]) break;
		ll cur = v - (n - (i - p + 1)); // 每个评委必须投的票数
		if (cur <= 0) { // 无票可投，第i票有机会被投
			ans++;
			continue;
		}
		if (cur * m <= (i - p + 1) * (a[i] + m) - (pref[i] - pref[p - 1]))
			// cur*m=必须投出的票数
			// (i-p+1)*(a[i]+m)=这(i-p+1)道题目最终的最高分数和
			// pref[i]-pref[p-1]=在[p-1,i)区间内的初始分数和
			// 二者相减=[p-1,i)这些题目所能投的最多票数（？？？？？？？？）
			ans++;
	}
	printf("%d\n", ans);
 
	return 0;
}










