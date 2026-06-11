#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define imin INT_MIN
#define imax INT_MAX
int mod =1e9+7;

int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio();
	ll x,k,d;

	cin>>x>>k>>d;
	ll ans;
	x=abs(x);

	ll req = (x/d);
		if(k>=req){
			k-=req;
			x-=d*req;
			if(k&1) {
				ans=abs(d-x);
			} else ans=x;
		} else {
			x-=d*k;
			ans=x;
		}

	cout<<ans;
	
	return 0;
}
