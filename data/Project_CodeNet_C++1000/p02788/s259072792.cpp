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

ll n , d , a; 
cin >> n >> d >> a ; 
vector<pair<ll,ll>> v(n) ; 
for(ll i = 0 ; i<n ; i++){
	ll k , l ; cin >> k>>  l  ;
	l = (a-1+ l)/a ; 
	// cout << l << endl;
	v[i] = {k,l};
}
sort(all(v)) ;

ll base = 1; 
while(base <= n)base *= 2; 
vector<ll> tree(2*base) ,lazy(2*base); 
for(ll i = 0 ; i<n ; i++){
	ll x = base + i ; 
	while(x>0){
		tree[x]+=v[i].second;
		// cout << x << " " << tree[x] << endl;
		x/=2;
	}
}


ll ans = 0 ; 
ll x = 0 ; 
while(x<n){
	// cout << x  << endl;
	ll ok = -1 ;

// if(tree[x + base] <= 0  )continue ;
ll j = x + base ; 
ll con = tree[j] ;
while(j>0){
	con += lazy[j];
	j/=2;
}
// cout << x << " " << con << " " << v[x] .second <<  endl;
if(con <= 0){x++;continue;}

ll low = x , high = n-1 ; 
while(low<=high){
	ll mid = low + (high - low) /2 ;

	if(v[mid].first <= v[x].first + 2*d ){
		ok= mid ; 
		low = mid + 1 ;
	}
	else high = mid -1 ;
}

// dec health x ..... ok  by v[x].first 
// cout << "ok " <<  x << " " << ok << endl;
ll l = x+base , r = ok + base ;
lazy[l] -= v[x].second ;
if(l!=r) lazy[r]-=con; 
while(l+1<r){
	if(!(l&1))lazy[l+1]-=con;
	if(r&1)lazy[r-1] -=con; 
	l/=2;
	r/=2;
}

ans += con;

x++;





}
cout << ans ;



	
}