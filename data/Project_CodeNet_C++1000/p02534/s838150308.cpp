#include <bits/stdc++.h>  

#define ll long long 
#define ull unsigned long long
#define M1 1000000007


#define for0(i, n) for (ll i = 0; i < (ll)(n); i++) // 0 based indexing
#define for1(i, n) for (ll i = 1; i <= (ll)(n); i++) // 1 based indexing
#define forc(i, l, r) for (ll i = (ll)(l); i <= (ll)(r); i++) // closed llerver from l to r r inclusive
#define forr0(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--) // reverse 0 based.
#define forr1(i, n) for (ll i = (ll)(n); i >= 1; i--) // reverse 1 based


#define pb push_back
#define fi first
#define se second



#define all(x) (x).begin(), (x).end() 
#define rall(x) (x).rbegin(), (x).rend() 

using namespace std;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef double ld;

bool inc(vi vec){   // tells if an array is NOn-decreasing or NOt in O(n) time complexity.
		forc(i,0,vec.size()-1){
				if(vec[i]<vec[i-1])return 0;
		}
		return 1;
}

bool dec(vi vec){
	forc(i,0,vec.size()-1){
				if(vec[i]>vec[i-1])return 0;
		}
		return 1;
}

bool isprime(ll n){    // miller rabin(deterministic version) with time complexity of O(log n).
		if(n<2)
				return false;
		for(ll x:{2,3,5,7,11,13,17,19,23,29,31,37}){
				if(n==x)
						return true;
				bool flag=true;
				ll r=1;
				ll t=1;
				while(r<=((n-1)>>__builtin_ctzll(n-1))){
						if(r&((n-1)>>__builtin_ctzll(n-1)))
								t=((ll)t*x)%n;
						x=((ll)x*x)%n;
						r<<=1;
				}
				if(t==1||t==n-1)
						flag=false;
				for(r=0;r<__builtin_ctzll(n-1);r++){
						t=((ll)t*t)%n;
						if(t==n-1)
								flag=false;
				}
				if(flag)
						return false;
		}
		return true;
}

ll binpow(ll a, ll b) {  // Time complexity-->log(n) 
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll addmod(ll a,ll b){
	return (a%M1 + b%M1)%M1;
}


//-----------------------------------------------------------END------------------------------------------------------------------------------//


void solve(){
    int k;cin>>k;
    string ans="";
    while(k--){
    	ans+= "ACL";
    }
    cout<<ans;
}



int main() {
		ios::sync_with_stdio(false);
		cin.tie(0);

		//cout.precision(10);
		//cout << fixed;
        
        /*ll size=1000000;
        vector<bool> isthisprime(size+5,true);

        isthisprime[0]=false;
        isthisprime[1]=false;
        
        forc(i,2,size){
        	if(isthisprime[i]){
        		for(ll j=i*2;j<=size;j+=i){
        			isthisprime[j]=false;
        		}
        	}
        }*/

		//ll tt;cin>>tt;
		//while(tt--){
			solve();
		//}
		return 0;
}


