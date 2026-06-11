/*   ꧁༒☬महाकाल☬༒꧂ ꧁༒ঔमहाकालঔ༒꧂
                   
                   ঔৣ۝महाकालᴳᵒᵈ۝ঔৣ            
 
 */ 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops"
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T, typename cmp=less<T>> using oset =tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long 
#define mod 1000000007
#define MOD 998244353
#define inf 100000000000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _it iterator
#define all(_x) _x.begin(),_x.end()
#define f first
#define s second
#define pb push_back
#define ar array
#define ld long double
void mahakal(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
}
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
char c[4]={'D' , 'R' , 'U' , 'L'};
const ll maxN=2e5+5;
ll n , a[maxN] , cnt[maxN];
void solve(){
	cin>> n ;
	for(ll i=0;i<n ;i++)cin>>a[i] , cnt[a[i]]++;
	ll mx=*max_element(a , a+n);
	 if(a[0] != 0 || cnt[0] != 1) {
        cout << 0 << endl;
        return ;
    }
	
	ll ans=1;
	for(ll i=0;i < mx; i++){
		for(ll j=1 ; j<=cnt[i+1] ; j++){
			ans = (ans * cnt[i])%MOD;
		}
	}
	cout<<ans<<endl;
}

int main(){
	mahakal();
	fast;
	ll t =1 ;
	//cin>> t ; 
	while(t--)solve();
	cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
	return 0;
}