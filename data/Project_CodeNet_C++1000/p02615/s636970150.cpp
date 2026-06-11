#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
typedef long long ll;
int n;
ll a[maxn];
ll ans;
bool cmp(ll x,ll y){return x>y;}
int main(){
	//freopen("data.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int lst=1,cnt=1;
	for(int i=2;i<=n;i++){
		ans+=a[lst];
		cnt--; if(cnt==0) lst++,cnt=2;
	}
	printf("%lld",ans);
}