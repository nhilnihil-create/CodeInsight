#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

int main() {
	cin>>n>>k;
	ll p[n+1], c[n+1], ans=-1e18;
	bool vis[n+1];
	memset(vis, 0, sizeof(vis));
	for (int i=1; i<=n; i++) {
		cin>>p[i];
	}
	for (int i=1; i<=n; i++) {
		cin>>c[i];
	}
	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			vector <ll> v;
			v.push_back(c[i]);
			vis[i]=1;
			ll x=i;
			while (!vis[p[x]]) {
				vis[p[x]]=1;
				x=p[x];
				v.push_back(c[x]);
			}
			ll u=v.size();
			for (int j=0; j<u; j++) {
				v.push_back(v[j]);
			}
			for (int j=1; j<=min(u, k); j++) {
				ll ps=0;
				for (int l=0; l<j; l++) {
					ps+=v[l];
				}
				ll temp=ps;
				for (int l=1; l<u; l++) {
					ps=ps-v[l-1]+v[l+j-1];
					temp=max(temp, ps);
				}
				ans=max(ans, temp);
			}
			if (k>u) {
				ll sum=0;
				for (int j=0; j<u; j++) {
					sum+=v[j];
				}
				if (sum>0) {
					ll cy=(k/u)*sum;
					ll sisa=k%u;
					for (int j=1; j<=sisa; j++) {
						ll ps=0;
						for (int l=0; l<j; l++) {
							ps+=v[l];
						}
						ll temp=ps;
						for (int l=1; l<u; l++) {
							ps=ps-v[l-1]+v[l+j-1];
							temp=max(temp, ps);
						}
						ans=max(ans, cy+temp);
					}
					cy-=sum;
					for (int j=1; j<=u; j++) {
						ll ps=0;
						for (int l=0; l<j; l++) {
							ps+=v[l];
						}
						ll temp=ps;
						for (int l=1; l<u; l++) {
							ps=ps-v[l-1]+v[l+j-1];
							temp=max(temp, ps);
						}
						ans=max(ans, cy+temp);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}