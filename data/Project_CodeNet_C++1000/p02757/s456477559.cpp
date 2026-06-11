#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
char s[N];
int cnt[10010];
int n, p;

int main()
{
	scanf("%d%d%s", &n, &p, s + 1);
	if(p == 2 || p == 5) {
		ll res = 0;
		for(int i = 1; i <= n; i++) {
			int v = s[i] - '0';
			if(v % p == 0) res += i;
		}
		
		return 0 * printf("%lld\n", res);
	}
	
	cnt[0] = 1;
	ll j = 1, now = 0, res = 0;
	for(int i = n; i >= 1; i--) {
		int v = s[i] - '0';
		now = (now + j * v) % p;
		res += cnt[now];
		cnt[now]++;
		j = j * 10 % p;
	}
	
	printf("%lld\n", res);
	
	return 0;
}