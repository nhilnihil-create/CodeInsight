// Do you knOW what it feels like?

		// To be TorTured by your own MinD?
	
	// I don't wanna feel the PAIN.

// I BeG you KILLING me, pleASE...

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())

typedef long long ll;
typedef pair<ll,ll> pll;

const ll maxn=1e5+10, mod=1e9+7, inf=1e18;

ll n;

ll p(ll i){ return n+i; }

int main(){
	
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	cin>>n;

	ll x=n; while(x%2==0) x/=2; if(x==1) return cout<<"No\n", 0;

	cout<<"Yes\n";
	cout<<"1 2\n";
	cout<<"2 3\n";
	cout<<3<<' '<<p(1)<<"\n";
	cout<<p(1)<<' '<<p(2)<<"\n";
	cout<<p(2)<<' '<<p(3)<<"\n";
		
	for(int i=4;i<n;i+=2){
		cout<<i<<' '<<i+1<<"\n";
		cout<<i+1<<' '<<1<<"\n";
		cout<<p(1)<<' '<<p(i)<<"\n";
		cout<<p(i)<<' '<<p(i+1)<<"\n";
	}

	if(n%2==0) cout<<n<<' '<<n-1<<"\n", cout<<p(n^(n-2))<<' '<<p(n)<<"\n";

	return 0;
}




















