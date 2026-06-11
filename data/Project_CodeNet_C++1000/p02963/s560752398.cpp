#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll mysqrt(ll x){
	ll l=1,r=2e9;
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

    ll x1=mysqrt(s);
    ll y2=x1;

    ll x2=x1*y2-s;

    ll y1=1;

    cout<<0<<' '<<0<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;

    return 0;
}
