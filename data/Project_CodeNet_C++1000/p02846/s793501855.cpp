#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll t[2],a[2],b[2],c[2];
ll p,q;

int main(void){
	rep(i,2)cin>>t[i];
	rep(i,2)cin>>a[i];
	rep(i,2)cin>>b[i];
	p=(a[0]-b[0])*t[0];
	q=p+(a[1]-b[1])*t[1];
	if(p>0){
		p=-p;
		q=-q;
	}
	if(q==0){
		cout<<"infinity"<<endl;
	}else if(q<0){
		cout<<0<<endl;
	}else{
		ll s=0,ans=0;
		s+=abs(p)/q;
		ans+=2*s;
		if(p+s*q<0)ans++;
		cout<<ans<<endl;
	}
	return 0;
}