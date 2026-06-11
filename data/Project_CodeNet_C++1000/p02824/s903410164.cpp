#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 1000000000000000000
ll n,m,v,p,a[100005],s;
int main(void){
    scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1,greater<ll>());
    for(int i=p;i<=n;i++)s+=m-a[i];
    for(ll i=n;i>=1;i--){
		s-=(m-a[i]);
		if(a[p]<=a[i]+m&&(p+n-i)*m+s+(i-p)*a[i]>=v*m){
			cout<<i<<endl;
			return 0;
		}
	}
}
