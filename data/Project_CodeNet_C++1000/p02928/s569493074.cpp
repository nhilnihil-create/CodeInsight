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
//using pll = pair<ll,ll> ;

ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	vll l(n,0),r(n,0) ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a.at(i)>a.at(j)){
				if(i>j) l.at(i)++ ;
				else r.at(i)++ ;
			}
		}
	}
	ll ans = 0 ;
	for(int i=0;i<n;i++){
		ll sub = k*(k+1)/2%mod*r.at(i)+k*(k-1)/2%mod*l.at(i) ;
		ans += sub%mod ;
		ans %= mod ;
	}
	cout << ans << endl ;
}
