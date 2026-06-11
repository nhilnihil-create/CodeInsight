#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ll> vll;

#define pvec(v) for(auto e: v) cout << e << " ";
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define pb push_back
#define INF 1000000000
#define MOD 1000000007

vector<ll> primes;
void sieve(int n){
	bool p[n+5];
	rep(i, 0, n+5) p[i] = true;
	p[0] = p[1] = false;

	for(int i = 2; i*i <= n; ++i){
		if(p[i]){
			for(int j = 2*i; j<=n; j+=i)
				p[j] = false;
		}
	}

	rep(i, 2, n+1)
		if(p[i])
			primes.push_back((ll)i);
}

ll power(ll x, ll y, ll p = MOD)  {  
    ll res = 1LL;
    x = x % p;
    if (x == 0) return 0; 
  
    while (y > 0){         
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
} 

int main(){
	IO
	//sieve(100000);

	ll n, k;
	cin >> n >> k;

	ll ans = 0LL, otherThanOne = power(k, n), term;
	ll dp[k+2] = {0};
	for(int i = k; i>=1; --i){
		dp[i] = power(k*1LL/i, n);
		term = 0LL;
		for(int j = 2*i; j<=k; j+=i){
			term = (term + dp[j]%MOD)%MOD;
		}
		dp[i] = (dp[i] - term)%MOD;
	}

	ll sum = 0LL;
	rep(i, 1, k+1){
		sum = (sum + i*dp[i]%MOD)%MOD;
		//cout << dp[i] << endl;
	}
	cout << sum << endl;
	return 0;
}