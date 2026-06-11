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
void solve(){
	string s ;
	cin>> s ;
	ll n = s.length();
	for(ll i=0;i<n ;i++){
		if(s[i]=='?')s[i]='D';
	}
	cout<<s<<endl;
}
int main(){
	//mahakal(),fast;
	ll t=1 ;
	// cin>> t;
	while(t--)solve();

	return 0;
}