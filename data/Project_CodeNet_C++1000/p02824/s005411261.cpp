#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
typedef long long ll;

const int Maxd=1e5+7;
int a[Maxd];
int n,m,p,v;
bool check(int d)
{
	if(d>=n-p)return true;
	ll zan=(ll) m*(ll) (v-p);
	ll lim=a[d]+m;
	for(int i=0;i+p<=n;i++)
	{
		if(i==d)continue;
		ll c=min((ll) m,(ll) lim-a[i]);
		if(c<0)return false;
		zan-=c;
	}
	return zan<=0;
}

int main()
{
	cin>>n>>m>>v>>p;
	REP(i,n)cin>>a[i];
	sort(a,a+n);
	int l=-1,r=n;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	 } 
	cout<<n-r<<endl;
	return 0;
}
