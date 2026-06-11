#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
#define inf 1000000000
#define mod 1000000007
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;

int n,a[200005],cnt[200005];
ll ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		ans+=(ll(cnt[i])*ll(cnt[i]-1))/2;
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans-cnt[a[i]]+1);
	return 0;
}