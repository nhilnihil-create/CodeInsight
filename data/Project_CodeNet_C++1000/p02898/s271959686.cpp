#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

int MOD = 1e9+7;

// ll po(ll b, ll p){ return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;}
// ll pomd(ll a, ll k, ll md) { ll p; if (k == 0){ return 1; } p = pomd(a, k / 2, md); p = p * p % md; if (k % 2){ p = p * a % md; } return p; }
// vi arr(N); for(int i{1}; i<N; ++i) for(int j=i; j<N; j+=i) d[j]++; // counting divisors
//bool isPrime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }

#define mp make_pair
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define rot(s, k) rotate(s.begin(), s.begin()+ s.size()-(k%s.size()), s.end()); //+ve = right, -ve = left

void setIO(string name = ""){
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}	

int main(){
 	ios_base::sync_with_stdio(0); cin.tie(0); 
	// setIO();
	int n, k; cin >> n >> k;

	int cnt = 0;
	for(int i{}; i<n; i++){
		int x; cin >> x;
		if(x>=k) cnt++;
	}

	cout << cnt << "\n";


}
