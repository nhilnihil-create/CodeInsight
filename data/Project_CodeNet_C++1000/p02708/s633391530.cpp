#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
ll l,r;
int ans = 0;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		l += i;
	}
	for(int i=n;i>n-k;i--){
		r += i;
	}
	for(int i=k;i<=n+1;i++){
		//printf("%d %lld %lld\n",i,l,r);
		int add = (r-l+1)%mod;
		ans = (ans+add)%mod;
		l += i;
		r += n-i;
	}
	printf("%d\n",ans);
}
