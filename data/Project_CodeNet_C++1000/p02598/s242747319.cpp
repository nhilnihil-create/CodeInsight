#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <typename T> T Max(T x,T y){return x>y?x:y;}
template <typename T> T Min(T x,T y){return x<y?x:y;}
template <typename T> T Abs(T x){return x>0?x:-x;}

int n,k,a[200005];

bool chk(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int t=a[i]%x==0?a[i]/x:a[i]/x+1;
		t--;
		cnt+=t;
		if(cnt>k) return false;
	}
	return true;
}

int main()
{
	int maxn=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=Max(maxn,a[i]);
	}
	int l=1,r=maxn,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}