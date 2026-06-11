#include<bits/stdc++.h>
#define int			long long
#define ll 			long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
using namespace std;

#define N  1000005

ll minprime[N];

void sieve(){
	for(ll i=2;i<N;i++){
		if(!minprime[i]){
			for(ll j=i*i;j<N;j+=i){
				if(!minprime[j]){
					minprime[j]=i;
				}
			}
			minprime[i]=i;
		}

	}
}

void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	rep(i,0,n){
		ll x;
		cin>>x;
		a[i]=x;
	}	
	ll g=a[0];
	rep(i,1,n)g=__gcd(g,a[i]);
	vi facs[n];
	ll tot=0;
	set<ll> s;
	rep(i,0,n){
		ll temp =a[i];
		ll mp =minprime[a[i]];
		while(temp>1){
			temp=temp/mp;
			if(sz(facs[i])==0 || facs[i][sz(facs[i])-1]!=mp){
				facs[i].pb(mp);
				tot++;
				s.insert(mp);
			}
			mp=minprime[temp];
		}
	}
	if(sz(s)!=tot){
		if(g==1){
			cout<<"setwise coprime"<<endl;
		}
		else{
			cout<<"not coprime"<<endl;
		}
	}
	else{
		// for(auto i:s)cerr<<i<<" ";
		// 	cerr<<endl;
		cout<<"pairwise coprime"<<endl;
	}


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	sieve();
	// rep(i,1,10)cerr<<minprime[i]<<endl;
	while(TESTS--)
	{
		solve();
	}
	return 0;
}