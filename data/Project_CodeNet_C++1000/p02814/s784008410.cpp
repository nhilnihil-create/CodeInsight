#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//解説見た


//2でなんかいわれるか
ll f(ll x){
	ll res = 0;
	while (x%2 == 0){
		x /= 2;
		res++;
	}
	return res;
}


ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main(){
	ll n,m;
	cin>>n>>m;
	ll a[n]={};
	for(ll i=0; i<n; i++){
		cin>>a[i];
		a[i]= a[i]/2;
	}
	//cout<<"a"<<endl;
	ll t=f(a[0]);
	//cout<<t<<endl;
	//リストaがすべてa/2**nで割れるかどうか
	for(ll i=0; i<n; i++){
		if( f(a[i]) != t){
			cout<< 0 << endl;
			return 0;
		}
		a[i] >>= t;
	}
	//cout<<"a"<<endl;
	ll l=1;
	for(ll i=0; i<n; i++){
		//cout<<a[i]<<" ";
		ll c=max(l,a[i]);
		ll b=min(l,a[i]);
		l= l * a[i]/gcd(c,b) ;
		//cout<<l<<" "<<endl;
	}
	//cout<<endl;
	//cout<<l<<endl;
	m = m>>t;
	m = m/l;
	m = (m+1)/2;
	cout<<m<<endl;
}
	