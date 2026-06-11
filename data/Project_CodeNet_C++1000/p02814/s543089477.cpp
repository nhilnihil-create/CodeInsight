#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pair tree<pair<int,int>,null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_mutiset tree<int,null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> pi; 
#define PI 3.1415926535897932384
#define FOR(i,vv,n) for(ll i=vv;i<n;i++)
#define FORR(i,n,vv) for(ll i=n-1;i>=vv;i--)
#define ve vector 
#define maxind(v) (max_element(v.begin(),v.end())-v.begin())
#define minind(v) (min_element(v.begin(),v.end())-v.begin())
#define maxe(v) *max_element(v.begin(),v.end())
#define mine(v) *min_element(v.begin(),v.end())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define M 1000000007ll
#define INF 1000000000000000000ll
#define PRECISE cout.precision(18);
#define all(v) v.begin(),v.end()
#define BS(v,n) binary_search(all(v),n)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(all(v),greater <ll>())
#define uni(v) v.resize(unique(all(v))-v.begin())
#define F first
#define S second
#define GET(i,p) get<p>(i)



int main(){

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt	
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	 #endif

    FAST
	//PRECISE


ll n,m;
cin>>n>>m;
ve <ll> v(n);
ll lcm=1;
ll ans=0;
FOR(i,0,n){
cin>>v[i];v[i]/=2;
if(ans!=-1)
lcm=(lcm*v[i])/(__gcd(lcm,v[i]));
if(lcm>m){
	ans=-1;
}
}
if(ans!=-1){
	FOR(i,0,n)
	if((lcm/v[i])%2==0)ans=-1;
}
if(ans==-1)ans=0;
else{
ll z1=m/lcm;
ans=z1/2+z1%2;}

cout<<ans;


// ll n;
// cin>>n;
// ve <ll> v(n);
// FOR(i,0,n)cin>>v[i];
// srt(v);

// ve <ll> fa(3*n);
// fa[0]=1;
// //fa[1]=2;
// FOR(i,1,3*n){
// fa[i]=2ll*fa[i-1];
// fa[i]%=M;
// }
// ll ans=0;
// ll c=1;
// FOR(i,0,n){
// 	ll k=n-i;
// 	ans+=(fa[2*k-2]*(k-1)+fa[2*k-1])%M*v[i]%M*c%M;
// 	c=c*2;
// 	c%=M;
// }
// cout<<ans;









return 0;
 }
