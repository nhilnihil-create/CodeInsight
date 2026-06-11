#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,l/l> ;
//#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

vll fac(2,1),inv(2,1),finv(2,1) ;

void nCr_set(ll n){
	for(int i=2;i<=n;i++){
		fac.emplace_back(fac.at(fac.size()-1)*i%mod) ;
		inv.emplace_back(mod-inv.at(mod%i)*(mod/i)%mod) ;
		finv.emplace_back(finv.at(finv.size()-1)*inv.at(i)%mod) ;
	}
}

ll nCr(ll n,ll r){
	if(n<0||r<0||n<r) return 0 ;
	if(n==r||r==0) return 1 ;
	return fac.at(n)*finv.at(n-r)%mod*finv.at(r)%mod ;
}

ll nHr(ll n,ll r) {
	return nCr(n+r-1,n-1) ;
}


int main(){
	nCr_set(5000) ;
	ll n,k ;
	cin >> n >> k ;
	if(n==k){
		for(int i=1;i<=k;i++){
			if(i==1) cout << 1 << endl ;
			else cout << 0 << endl ;
		}
		return 0 ;
	}
	for(int i=1;i<=k;i++){
		ll ans = 0 ;
		ll sub = nHr(i,k-i) ;
		ans += nHr(i-1,n-k-i+1)*sub ; ans %= mod ;
		ans += 2*nHr(i,n-k-i)*sub ; ans %= mod ;
		ans += nHr(i+1,n-k-i-1)*sub ; ans %= mod ;
		cout << ans << endl ;
	}
}
