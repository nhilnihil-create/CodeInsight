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

ll n,a[510][510];

void f(V<ll> &v, ll x){
	ll n = v.size();
	if(n<=1)return;
	V<ll> v1,v2;
	rep(i,n/2)v1.push_back(v[i]);
	reg(i,n/2,n-1)v2.push_back(v[i]);
	for(ll p:v1){
		for(ll q:v2){
			a[p][q]=x;
		}
	}
	f(v1,x+1);
	f(v2,x+1);
}

void init(){
	cin>>n;
}

int main(void){
	init();
	V<ll> v;
	rep(i,n)v.push_back(i);
	f(v,1);
	rep(i,n){
		reg(j,i+1,n-1)cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}