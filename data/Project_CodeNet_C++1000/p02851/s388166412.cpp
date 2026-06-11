#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;
int a[maxn],s[maxn],n,k;
map<int,int> m;
long long ans;

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		s[i]=(s[i-1]+a[i])%k;
	}
	for(int i=1;i<=n;++i) s[i]=((s[i]-i)%k+k)%k;
	for(int i=0;i<=n;++i) {
		if(i-k>=0) m[s[i-k]]--;
		ans+=m[s[i]];
		m[s[i]]++;
	}
	printf("%lld",ans);
}