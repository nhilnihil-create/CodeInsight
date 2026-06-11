#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
 
int A[SIZE];
int n,m,v,p;
bool check(int d)
{
	if(d>=n-p) return true;
	int lim=A[d]+m;
	ll zan=(ll) m*(ll) (v-p);
	int cnt=0;
	for(int i=0;i+p<=n;i++)
	{
		if(i==d) continue;
		ll c=min((ll) m,(ll) lim-A[i]);
		if(c<0) return false;
		zan-=c;
	}
	return zan<=0;
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&v,&p);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	int l=-1,r=n;
	while(r-l>1)
	{
		int d=(l+r)/2;
		if(check(d)) r=d;
		else l=d;
	}
	printf("%d\n",n-r);
	return 0;
}