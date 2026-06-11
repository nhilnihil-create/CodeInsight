#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
    
#define ll long long int
#define pb push_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define pre(i , j , n) for(ll i = j ; i >= n ; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<char>	vc;
typedef vector<bool>	vb;
typedef pair<ll,ll> 	pll;
#define br "\n"
#define ff first
#define ss second
#define MAX 1000003

ll mod = 1e9 + 7;

vll prime(MAX,0);

void sieve() 
{ 
    prime[0] = prime[1] = 1; 
    for (ll i = 2; i < MAX; i++) { 
        if (prime[i] == 0) { 
            for (ll j = i * 2; j < MAX; j += i) { 
                if (prime[j] == 0) { 
                    prime[j] = i; 
                } 
            } 
            prime[i] = i; 
        } 
    } 
} 

void solve(){ 
    ll n;
    cin >> n;
    ll ans=0;
    rep(i,1,n){
        ll x = n - i;
        if(x == 1){ 
            ans += 1;
            continue;
        }
        if(x == 0) {
            continue;
        }
        map<ll,ll> m;
        while(x != 1){
            m[prime[x]]++;
            x /= prime[x];
        }
        ll temp=1;
        for(auto x:m){
            temp *= (x.ss + 1);
        }
        ans += temp;
    }
    cout << ans;

}
	

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	ll t = 1;
	// cin >> t;
    sieve();
	rep(i,0,t){
		solve();
	}
 
}	