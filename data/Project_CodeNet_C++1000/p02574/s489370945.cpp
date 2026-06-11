#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;
const ll mod = 1e9 + 7;
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	return b == 0 ? a : gcd(b, a%b);
}
int n;
int vis[N], a[N], isp[N];
bool ck() {
	for (int i = 2; i < N; i++) {
		if (isp[i])continue;
		int cnt = 0;
		for (int j = i; j < N; j += i) {
			isp[i] = 1;
			cnt += vis[j];
		}
		if (cnt > 1)return false;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]), vis[a[i]]++;
	if (ck()) { puts("pairwise coprime"); return 0; }
	int g = a[1];
	for (int i = 2; i <= n; i++)g = gcd(g, a[i]);
	if (g == 1)puts("setwise coprime");
	else puts("not coprime");
	return 0;
}