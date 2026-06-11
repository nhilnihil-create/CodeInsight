#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line


vector<pair<long long,int>> factorize(long long n){
	vector<pair<long long,int>> res;
	for( long long i = 2; i*i <= n; ++i){
		if(n%i) continue ; 
		res.emplace_back(i,0);
		while(n%i == 0){
			n /= i ;
			res.back().second++;
		}
	}
	if ( n != 1) res.emplace_back(n,1);
	return res;
}
int main()
{
	ll n;
	cin >> n;
	// √nまでやればいい
	auto p = factorize(n-1);
	ll ans = 1;
	for(auto x: p){
		ans *= x.second + 1;
	}
	for(ll i = 2; i * i <= n; i++){
		if((n) % i == 0) {
			ll N = n;
			while(N % i == 0){
				N /= i;
			}
			if(N % i == 1){
				ans ++;
			}
		}
	}
	if(n == 2 || n == 3){
		cout << n - 1 << endl;
	} else {
		cout << ans  << endl;
	}
}
