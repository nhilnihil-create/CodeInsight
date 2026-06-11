#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using o_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define M 1000010

int main(){
	IOS;
	
	ll n;cin>>n;
	ll s=0,di=0;
	rep(i,0,n){
		ll d,c;cin>>d>>c;
		s+=d*c;
		di+=c;
	}
	ll f= (s-9)%9==0 ? (s-9)/9 : (s-9)/9+1; 
	if(s<9)f=0;
	cout<<(di-1)+f;
	return 0;
}

