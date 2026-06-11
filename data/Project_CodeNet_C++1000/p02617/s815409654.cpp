#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int l[200005],r[200005];

int main(void){
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=(ll)i*(n+1-i);
	}
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]>r[i]){
			swap(l[i],r[i]);
		}
		ll val=(ll)l[i]*(n-r[i]+1);
		ans-=val;
	}
	printf("%lld\n",ans);
	return 0;
}
