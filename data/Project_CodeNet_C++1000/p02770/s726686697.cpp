//by szh
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define SZ(x) (int((x).size()))
#define se second
#define ll long long
#define pq priority_queue
#define MP make_pair
#define pii pair<int,int>
#define mod 998244353
#define debug(x) cerr<<#x<<"="<<x<<'\n'

int k,q;
int a[5010],b[5010];
ll sum1[5010],sum[5010];

int main(){
	scanf("%d%d",&k,&q);
	for (int i=1;i<=k;i++) scanf("%d",&a[i]);
	for (int i=0;i<q;i++) {
		int n,x,m;
		scanf("%d%d%d",&n,&x,&m);
		x%=m;
		n--;
		for (int i=1;i<=k;i++) b[i]=a[i]%m;
		for (int i=1;i<=k;i++) sum1[i]=sum1[i-1]+(b[i]>0),sum[i]=sum[i-1]+(ll)b[i];
		ll tmp1=n/k*sum1[k]+sum1[n%k];
		ll tmp2=(ll)n/k*(ll)sum[k]+(ll)sum[n%k]+(ll)x;
//		cout<<tmp2<<endl;
		cout<<(ll)tmp1-tmp2/(ll)m<<endl;
	}
	return 0;
}
