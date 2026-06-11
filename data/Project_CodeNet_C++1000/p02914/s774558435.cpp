#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
ll a[100010];
int main() {
	scanf("%d",&n);
	int i,j;
	ll x=0;
	for(i=0;i<n;i++)scanf("%lld",a+i),x^=a[i];
	for(i=0;i<n;i++) {
		a[i]|=x;a[i]-=x;
	}
	int cur=0; ll r=0;
	for(j=62;j>=0;j--) {
		for(i=cur;i<n;i++) {
			if(a[i]>>j&1){ 
				swap(a[i],a[cur]);
				break;
			}
		}
		for(i=0;i<n;i++) {
			if(i!=cur&&a[i]>>j&1) a[i]^=a[cur];
		}
		if(a[cur]>>j&1) cur++;
	}
	for(i=0;i<cur;i++)r^=a[i];
	printf("%lld",x+r*2);
	return 0;
}