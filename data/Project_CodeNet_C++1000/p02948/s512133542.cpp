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
bool cmp(pair<ll,ll> p1 , pair<ll,ll>p2){
	// if(p1.f==p2.f){
	// 	return p1.s>p2.s;
	// }
	return p1.f>p2.f;
}
int main(){
	//mahakal(),fast;
	ll n ,m ;
	cin>> n >> m ;
	vector<pair<ll,ll>> vec;
	for(ll i=0,a,b ;i< n ;i++){
		cin>>a>>b ;
		vec.pb({b,a});
	}
	sort(vec.begin(),vec.end(),cmp);
	ll slot[m+1]={0};
	ll ans=0;
	set<ll> st ;
	for(ll i=0;i<=m ;i++)st.insert(i);
	for(ll i=0;i<n ;i++){
		ll idx=m-vec[i].s;
		if(idx<0)continue;
		// for(ll j=idx;j>=0 ; j--){
		// 	if(slot[j]==0){
		// 		slot[j]=vec[i].f;
		// 		break;
		// 	}
		// }
		auto ps=st.lower_bound(idx);
		if(*ps==idx){
			ans+=vec[i].f;
			st.erase(ps);
		}
		else{
			if(ps==st.begin())continue;
			else{
				--ps;
				ans+=vec[i].f;
				st.erase(ps);
			}
		}
	}
	// for(ll i=0;i<=m;i++)ans+=slot[i];
	cout<<ans<<endl;

	return 0;
}