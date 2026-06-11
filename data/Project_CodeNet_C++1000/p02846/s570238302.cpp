#include <iostream>
//#include <iomanip>
//#include <string>
//#include <vector>
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
//using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}]

int main(){
	ll t1,t2,a1,a2,b1,b2 ;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2 ;
	if(t1*a1+t2*a2==t1*b1+t2*b2) cout << "infinity\n" ;
	else{
		if(a1<b1){
			swap(a1,b1) ;
			swap(a2,b2) ;
		}
		ll d1 = t1*(a1-b1) ;
		ll d2 = t2*(a2-b2) ;
		if(d1+d2>0) cout << 0 << endl ;
		else{
			ll ans = (d1/abs(d1+d2)+1)*2-1 ;
			if(d1%abs(d1+d2)==0) ans-- ;
			cout << ans << endl ;
		}
	}
}
