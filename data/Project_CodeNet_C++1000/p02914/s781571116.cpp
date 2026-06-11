#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define abs(a) (a>0?a:(-(a)))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
ll a[100050],b[100];
int main(){
	int n;
	ll s=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s^=a[i];
	}
	for (int i=1;i<=n;i++){
		int f=0;
		ll t=a[i];
		for (int j=60;j>=0;j--)
		if (!(s&(1ll<<j))) {
			if (a[i]&(1ll<<j)) {
				if (!b[j]) {
					b[j]=a[i];
					f=1;
					break;
				}else a[i]^=b[j];
			}
		}
		if (f) continue;
		a[i]=t;
		for (int j=60;j>=0;j--)
		if (a[i]&(1ll<<j)) {
			if (!b[j]) {
				b[j]=a[i];
				break;
			}else a[i]^=b[j];
		}
	}
	ll ans=0;
	for (int i=60;i>=0;i--)
	if (!(ans&(1ll<<i))) ans=ans^b[i];
	printf("%lld\n",ans+(s^ans));
	return 0;
}