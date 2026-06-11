#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
#include <set>
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
//#define all(v) v.begin(),v.end()
//ll mod = 1e9+7 ;
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
	set<int> s ;
	s.insert(0) ; s.insert(-1) ;
	s.insert(n+1) ; s.insert(n+2) ;
	vll pos(n+1,-1) ;
	for(int i=0;i<n;i++) pos.at(a.at(i)) = i+1 ;
	ll ans = 0 ;
	for(int i=n;i>=1;i--){
		int w,x,y,z ;
		auto itr = s.lower_bound(pos.at(i)) ; itr++ ;
		z = *itr ; itr-- ;
		y = *itr ; itr-- ;
		x = *itr ; itr-- ;
		w = *itr ;
		if(w==-1) w = 0 ;
		if(z==n+2) z = n+1 ;
		ans += (x-w)*(y-pos.at(i))*i+(pos.at(i)-x)*(z-y)*i ;
		s.insert(pos.at(i)) ;
//		cout << ans << endl ;
//		cout << w << " " << x << " " << y << " " << z << endl ;
	}
	cout << ans << endl ;
}
