#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
const ld pi = 3.14159265358979;
    
int run_test(){
	ll a, b;
	cin >> a >> b;
	ll g = __gcd(a, b);
	//now I have to find all the prime factors of g
	int count = 0;
	for(int i=2; i<=sqrt(g); i++){
		if(g % i == 0){
			count++;
			while(g % i == 0){
				g /= i;
			}
			if(g == 1) break;//this means all the prime numbers have been visited 
			//there is no need of looping over remaining elements
		}
	}//what if after looping, still g is not equal to 1
	//this means that g is a prime number which divides the gcd(a,b)
	//therefore add 1 to the count
	if(g != 1) count++;
	cout << count + 1;
	return 0;
}
    
int main(){
   FAST;
    ll t;
    t = 1;
     
    while(t--){
        run_test();
    }
}