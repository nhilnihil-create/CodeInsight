/*   ꧁༒☬महाकाल☬༒꧂ ꧁༒ঔमहाकालঔ༒꧂
                   
                   ঔৣ۝महाकालᴳᵒᵈ۝ঔৣ            
 
 */ 
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T, typename cmp=less<T>> using oset =tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long 
#define mod 1000000007
#define inf 100000000000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _it iterator
#define all(_x) _x.begin(),_x.end()
#define f first
#define s second
#define pb push_back
void mahakal(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
}
bool check(ll* a , ll* b ,ll n , ll k , ll mid){
	ll ans = 0 ;
	for(ll i=0;i< n ;i++){
		if(a[i]*b[i]>mid){
			ans += a[i]-mid/b[i];
		}
	}
	return ans <= k;
}
int main(){
	//mahakal(),fast;
	
	ll n , k ;
	cin>> n >> k ;
	ll a[n],b[n];
	for(ll i=0;i< n ;i++)cin>>a[i];
	for(ll i=0;i< n ;i++)cin>>b[i];
	sort(a,a+n);
	sort(b,b+n,greater<ll>());
	ll ans = 0;
	ll l=0 , r=inf;
	while(l<=r){
		ll mid=(l+r)/2;
		bool ps=check(a,b,n,k,mid);
		if(ps){
			ans=mid;
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	cout<<ans<<endl;

	return 0;
}