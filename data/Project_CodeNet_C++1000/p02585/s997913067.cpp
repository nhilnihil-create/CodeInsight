#include<bits/stdc++.h>
#define ll long long
#define fr(i,n) for(i=1;i<=n;i++)
using namespace std;
int main()
{
	ll n,K,i;
	cin>>n>>K;
	ll p[n+10],c[n+10];
	p[0]=c[0]=0;
	fr(i,n) cin>>p[i];
	fr(i,n) cin>>c[i];
	ll m=-(1LL<<55),M=-(1LL<<55);
	fr(i,n){
		ll x=i,k=K;
		vector<ll>v;
		ll sum=0,rnd=0;
		while(1){
			sum+=c[x];
			m=max(m,sum);
			v.push_back(c[x]);
			x=p[x];
			rnd++;
			if(x==i || rnd==k) break;
		}
		k-=rnd; /*cout<<rnd<<'\n';
		for(auto it:v) cout<<it<<' ';cout<<'\n';*/
		if(k!=0){
			ll z=k/rnd;
			if(z!=0)
			sum+=(sum*(z-1)),
			k-=(rnd*(z-1));
			else k=k%rnd;
			m=max(m,sum);
			for(int j=0;j<k;j++){
				sum+=v[j%rnd];
				m=max(m,sum);
			}
		}
		M=max(m,M);
		//cout<<M<<' '<<m<<'\n';
		m=-(1LL<<55);
	}
	cout<<M<<"\n";
}