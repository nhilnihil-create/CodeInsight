// first second push_back unordered return continue break vector visited check flag bool while iterator begin end lower_bound upper_bound temp true false ll_MAX ll_MIN insert erase clear pop push compare ll64_MAX ll64_MIN  reverse replace stringstream string::npos length substr front priority_queue
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
const ll mod = 1e9 + 7 ;
const ll inf =
 1e9 + 5 ;
 //1e18L + 5;
const ll nax = 2e5 + 5;
void min_self(ll&a , ll b){a=min(a,b);}
void max_self(ll&a , ll b){a=max(a,b);}
void add_self(ll&a , ll b){a=(a+b)%mod;}
//#define (x)  get<0>(x) 
//#define (x)  get<1>(x)
//#define (x)  get<2>(x)
signed main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n , d, a;  
cin >> n>> d >> a; 
vector<pair<ll,ll>> v(n) ;
for(ll i = 0 ; i<n ; i++){
	ll k , l ; 
	cin >> k >> l ; 
	l = (a - 1 + l)/a ;
	v[i] = {k , l };
}
sort(all(v)) ;
// for(auto it:v)cout<<it.first << " j " << it.second << endl;
vector<ll> arr(n+1) ; 
ll ans = 0 ;
for(ll i = 0 ; i<n ; i++){
// for(auto it: arr)cout<<it<<" " ;cout << endl;

v[i].second += arr[i]  ;
if(v[i].second <= 0 ){
	arr[i+1] += arr[i] ; 
	continue ;
}
// cout <<i << " " << v[i].second << endl;
ll low = i , high  = n-1 ; 
ll ok  ;
while(low <= high ){
	ll mid = low + (high - low) /2; 
	if(v[mid].first <= v[i].first + 2*d){
		ok = mid; 
		 low = mid + 1 ; 
	}
	else high = mid -1 ; 
}
// cout << "ok "  << i << " " << ok << endl;

arr[i] -= v[i].second ;
// if(i!=0)arr[i] += arr[i-1];
arr[ok+1] += v[i].second ;
arr[i+1] += arr[i];
ans += v[i].second ;

}

cout << ans ; 

	
}