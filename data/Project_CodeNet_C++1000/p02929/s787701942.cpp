#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const int Maxn=1e5;
const ll Mod=1e9+7;

int N;
char s[Maxn*2+5];

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&N);
	scanf("%s",s+1);
	ll ans=1,cnt=0,tmp=0;
	for(int i=1;i<=N*2;i++)
		if((cnt&1)^(s[i]=='B'))
			cnt++;
		else ans=(ans*cnt)%Mod,cnt--,tmp++;
	for(int i=1;i<=N;i++)
		ans=ans*i%Mod;
	printf("%lld\n",tmp==N?ans:0);
	return 0;
}