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
//using vvll = vector<vll> ;
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

int main(){
	ll n ; cin >> n ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	sort(all(a)) ;
	ll ans = 0 ;
	for(int i=0;i<n;i++) ans += abs(a.at(i)) ;
	if(a.at(0)*a.at(n-1)>0) ans -= 2*min(abs(a.at(0)),abs(a.at(n-1))) ;
	cout << ans << endl ;
	if(a.at(0)*a.at(n-1)>0){
		if(a.at(0)+a.at(n-1)<=0){
			reverse(all(a)) ;
			cout << a.at(0) << " " << a.at(1) << endl ;
			ll now = a.at(0)-a.at(1) ;
			for(int i=2;i<n;i++){
				cout << now << " " << a.at(i) << endl ;
				now -= a.at(i) ;
			}
		}else{
			cout << a.at(0) << " " << a.at(1) << endl ;
			ll now = a.at(0)-a.at(1) ;
			for(int i=2;i<n-1;i++){
				cout << now << " " << a.at(i) << endl ;
				now -= a.at(i) ;
			}
			cout << a.at(n-1) << " " << now << endl ;
		}
	}else{
		ll pos = 0 ;
		while(a.at(pos)*a.at(pos+1)>0) pos++ ;
		if(pos==n-2){
			ll now = a.at(n-1) ;
			for(int i=n-2;i>=0;i--){
				cout << now << " " << a.at(i) << endl ;
				now -= a.at(i) ;
			}
		}else{
			ll now = a.at(pos) ;
			for(int i=pos+1;i<n-1;i++){
				cout << now << " " << a.at(i) << endl ;
				now -= a.at(i) ;
			}
			cout << a.at(n-1) << " " << now << endl ;
			now = a.at(n-1)-now ;
			for(int i=pos-1;i>=0;i--){
				cout << now << " " << a.at(i) << endl ;
				now -= a.at(i) ;
			}
		}
	}
}
