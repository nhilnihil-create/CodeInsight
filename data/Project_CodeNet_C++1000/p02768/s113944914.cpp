#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()
#define FOR(I, A, B) for(int I = A; I < B; I++)
#define RFOR(I, A, B) for(int I = A; I >= B; I--)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

ll poww(ll a, ll e){
	if(e == 0) return 1;
	ll ans = poww(a, e/2);
	ans *= ans;
	ans %= MOD;
	if(e%2){
		ans *= a;
		ans %= MOD;
	}
	return ans;
}

ll invmod(ll x){
	return poww(x, MOD-2);
}

ll comb(ll a, ll n){
	ll ans = 1;
	for(ll i = n; i >= n-a+1; i--){
		ans *= i;
		ans %= MOD;
	}
	for(ll i = 1; i <= a; i++){
		ans *= invmod(i);
		ans %= MOD;
	}
	return ans;
}

ll sub(ll a, ll b){
	ll ans = a-b;
	if(ans < 0) ans+=MOD;
	return ans%MOD;
}

int main(){
	ll n, a, b;
	scanf("%lld %lld %lld", &n, &a, &b);
	ll ans = poww(2, n);
	ll tosub = 1 + comb(a,n) + comb(b,n);
	tosub %= MOD;
	ans = sub(ans,tosub);
	printf("%lld\n", ans);
	return 0;
}

