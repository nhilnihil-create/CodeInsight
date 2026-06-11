#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=10000000000;
int main() {
	int n,k;
	cin>>n>>k;
	vector<int> p(n);
	for(int i=0;i<n;i++) {
		cin>>p[i];
		p[i]--;
	}
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>c[i];
	if(k<=n) {
		ll ans=-INF;
		for(int i=0;i<n;i++) {
			ll P=i,s=0;
			for(int j=0;j<k;j++) {
				P=p[P];
				s+=c[P];
				ans=max(ans,s);
			}
		}
		cout<<ans<<endl;
	}
	else {
		vector<vector<int> > next(31,vector<int>(n) );
		for(int i=0;i<n;i++) next[0][i]=p[i];
		for(int i=1;i<31;i++) 
			for(int j=0;j<n;j++)
				next[i][j]=next[i-1][next[i-1][j]];
		vector<vector<ll> > sum(31,vector<ll>(n) );
		for(int i=0;i<n;i++) sum[0][i]=c[p[i]];
		for(int i=1;i<31;i++) 
			for(int j=0;j<n;j++) 
				sum[i][j]=sum[i-1][j]+sum[i-1][next[i-1][j]];
		ll ans=0;
		for(int i=0;i<n;i++) {
			ll P=i;
			ll s=0;
			for(int j=0;j<n;j++) {
				P=p[P];
				s+=c[P];
				ans=max(ans,s);
			}
			P=i;s=0;
			for(int j=0;j<31;j++) {
				if((k-n)>>j & 1) {
					s+=sum[j][P];
					P=next[j][P];
				}
			}
			ans=max(ans,s);
			for(int j=0;j<n;j++) {
				P=p[P];
				s+=c[P];
				ans=max(ans,s);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
