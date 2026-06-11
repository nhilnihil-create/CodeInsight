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
// char c[4]={'D' , 'R' , 'U' , 'L'};
const ll maxN=3e5+5;
ll n ;
bool cmp(pair<ll,ll> p1 , pair<ll,ll>p2){
    ll ans1 = p1.f+p1.s , ans2 = p2.f+p2.s;
    return ans1<ans2;
}

bool cmp1(pair<ll,ll> p1 , pair<ll,ll>p2){
    ll ans1 = p1.f-p1.s , ans2 = p2.f-p2.s;
    return ans1<ans2;
}

void solve(){
   cin>> n ;
   vector<pair<ll,ll>> a(n), b(n);
   for(ll i=0;i<n ;i++){
       cin>>a[i].f>>a[i].s;
       b[i].f=a[i].f , b[i].s = a[i].s;
   }
   sort(a.begin() , a.end() , cmp);
   sort(b.begin() , b.end() , cmp1);
   ll ans = max(abs(a[0].f-a[n-1].f) + abs(a[0].s - a[n-1].s) , abs(b[0].f-b[n-1].f) + abs(b[0].s - b[n-1].s));
   
   
   cout<<ans<<endl;
    
}

int main(){
// 	mahakal();
	fast;
	ll t =1 ;
// 	cin>> t ; 
	while(t--)solve();
// 	cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
	return 0;
}
