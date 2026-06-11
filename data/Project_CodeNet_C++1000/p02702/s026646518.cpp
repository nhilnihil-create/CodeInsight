#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;
const int mod = 2019;
int cnt[mod+10],Pow[N+100];
char str[N+100];

int main()
{
	cnt[0] = 1;
	Pow[0] = 1;
	for(int i=1;i<=N;i++){
		Pow[i] = (Pow[i-1]*10)%mod;
	}
	scanf("%s",str);
	int cur = 0;
	ll ans = 0;
	for(int sz=strlen(str),i=sz-1;i>=0;i--){
		int c = str[i]-'0';
		cur = (cur+(c*Pow[sz-1-i])%mod)%mod;
		ans += cnt[cur];
		cnt[cur]++;
	}
	printf("%lld\n",ans);
}
