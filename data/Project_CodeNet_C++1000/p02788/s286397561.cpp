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
vector<ll> tree , lazy  ; 
ll base ;
ll poll_query(ll p){
	ll res = tree[p+base];
	ll x = p + base ; 
	while(x>0){
		// cout << x << endl;
		res += lazy[x];
		x/=2;
	}
	return res ;
}

void update(ll l , ll r , ll val ){
	l += base ;
	r += base ; 
	lazy[l]+=val;
	if(l!=r)lazy[r]+=val;
	while(l+1 < r){
		if(!(l&1))lazy[l+1] += val ;
		if(r&1)lazy[r-1] += val;
		l/=2 ;
		r/=2;
	}
}




signed main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll n ,d , a ;cin >> n >> d >> a ; 
vector<pair<ll,ll>> v(n) ; 
for(ll i = 0 ; i<n ; i++){
	ll k , l ; 
	cin >> k >> l ; 
	 l = (a-1 + l )/a ; 
	 v[i] = {k , l };
}
sort(all(v));
ll ans = 0 ;
base = 1 ; 
while(base < n)base *=2 ; 
tree.resize(2*base) ; 
lazy.resize(2*base ) ;

for(ll i = 0  ;i< n ; i++){
	ll x = i + base ; 
	// tree[x] = v[i].second;
	while(x>0){
		tree[x] += v[i].second ; 
		x/=2;
	}
}

for(ll x = 0 ; x < n ; x ++){

ll res = 0 ;
// find res ;
res = poll_query(x) ; 
// cout << x << " " << res << endl;
if(res <=0  )continue ; 

ll low = x , high = n-1; 
ll ok ; 
while(low <= high ){
	ll mid = low + (high - low) / 2; 
	if(v[mid].first <= v[x].first + 2*d){
		ok = mid;  
		low = mid + 1; 
	}
	else{
		high = mid - 1 ;
	}
}

// update x....ok ( -res ) ;
update(x , ok  , -res) ;
ans += res;

}
cout << ans; 



	

	
}