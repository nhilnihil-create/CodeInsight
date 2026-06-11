#include <bits/stdc++.h>
#define mem(s,t) memset(s,t,sizeof(s))
#define pb(s) push_back(s)
#define inf 0x3f3f3f3f
#define mn 200010
typedef long long ll;
using namespace std;
const ll MOD=1e9+7;
char s[mn];
int a[mn];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int cnt=0;
	bool ok=1;
	for(int i=0;i<2*n;++i){
		if(s[i]=='B'){
			if(cnt&1){
				a[i]=0;--cnt;
			}
			else {
				a[i]=1;++cnt;
			}
		}
		else {
			if(cnt&1){
				a[i]=1;++cnt;
			}
			else {
				a[i]=0;--cnt;
			}
		}
		if(cnt<0){ok=0;break;}
	}
	if(cnt)ok=0;
	ll ans=1;
	if(ok){
		ll lc=0;
		for(int i=0;i<2*n;++i){
			if(a[i])++lc;
			else {
				ans*=lc--;
				ans%=MOD;
			}
		}
		for(int i=1;i<=n;++i){
			ans=(ans*i)%MOD;
		}
	}
	else ans=0;
	printf("%lld\n",ans);

    return 0;
}

