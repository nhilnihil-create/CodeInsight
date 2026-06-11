#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
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
using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
//void chmin(ll &a,ll b){if(a>b) a = b ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	vll a(n),b(n) ;
	for(auto &i:a) cin >> i ;
	for(auto &i:b) cin >> i ;
	sort(all(a)) ;
	sort(all(b)) ;
	reverse(all(b)) ;
	ll l,r,m ;
	l = -1 ;
	r = 100000000000000 ;
	while(l+1<r){
		m = (l+r)/2 ;
		ll cnt = 0 ;
		for(int i=0;i<n;i++){
			ll sub = m/b.at(i) ;
			if(a.at(i)>sub) cnt += a.at(i)-sub ;
		}
		if(cnt<=k) r = m ;
		else l = m ;
	}
	cout << r << endl ;
}
