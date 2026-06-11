#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi =acos(-1.0);
const int maxn=2e5+5;
int mysqrt(ll x){
	ll l=1,r=1e10;
	while(l<r){
		ll mid=(l+r)>>1;
		if(mid*mid<x)l=mid+1;
		else r=mid;
	}
	return l;
}

int main(){
    ll s;
    cin>>s;

    int x1,x2,y1,y2;
    x1=y2=mysqrt(s);

    x2=1;
    y1=1ll*x1*y2-s;

    cout<<0<<' '<<0<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;



	return 0;
}

