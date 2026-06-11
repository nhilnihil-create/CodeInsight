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
	ll n  ; cin >> n ; 

	vector<vector<ll>> dp(10 ,vector<ll>(10)) ; 
	for(ll i = 1 ; i<10 ; i++){
		dp[i][i] = 1;
	}
	ll ans = min(n  , 9LL) ;
	for(ll i = 10 ; i<= n ;i++){

		if(i%10==0){
			continue ; 
		}
		ll x = i ;  
		ll rev = i%10;
		while(x/10>0){
			x/=10;
		}
		rev = rev*10 + x%10;

		dp[rev%10][rev/10]++;
		if(rev/10 != rev%10)ans += 2*dp[rev/10][rev%10];
		else ans += 2*dp[rev/10][rev%10] - 1;
		// cout << i << " " <<ans << endl;


	}

	cout << ans;

	
}