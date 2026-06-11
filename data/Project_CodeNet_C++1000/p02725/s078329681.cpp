#include<bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

int k,n;
int a[200005],dist[200005];

int main()
{
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
		dist[i]=a[i]-a[i-1];
	dist[1]=k-a[n]+a[1];
	int maxn=-1,sum=0;
	for(int i=1;i<=n;i++)
	{
		chmax(maxn,dist[i]);
		sum+=dist[i];
	}
	printf("%d\n",sum-maxn);
	return 0;
}