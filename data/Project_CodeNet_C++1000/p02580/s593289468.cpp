#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define ii pair<int,int>
#define mod 1000000007
#define endl '\n'
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

void sieve(int n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(int p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<" ";
	}
}

int main() {
	IOS;
	int t=1;
	//cin>>t;
	while(t--){
		int h,w,m;
		cin>>h>>w>>m;
		int a[h+1],b[w+1];
		fill(a,a+h+1,0);
		fill(b,b+w+1,0);
		set<pair<int,int>> v;
		for(int i=0;i<m;i++){
			int p,q;
			cin>>p>>q;
			v.insert({p,q});
			a[p]++;
			b[q]++;
		}
		int ma1=0,ma2=0;
		for(int i=1;i<=h;i++){
			ma1=max(ma1,a[i]);
		}
		for(int i=1;i<=w;i++){
			ma2=max(ma2,b[i]);
		}
		vector<int> v1,v2;
		for(int i=1;i<=h;i++){
			if(a[i]==ma1)
				v1.push_back(i);
		}
		for(int i=1;i<=w;i++){
			if(b[i]==ma2)
				v2.push_back(i);
		}
		bool flag=false;
		for(auto i:v1){
			for(auto j:v2){
				if(v.count({i,j}))
					continue;
				flag=true;
				break;
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<ma1+ma2;
		else
			cout<<ma1+ma2-1;
	}
	return 0;
}