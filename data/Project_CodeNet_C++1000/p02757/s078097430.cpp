#include <iostream>
//#include <iomanip>
#include <string>
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
using vll = vector<int> ;
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
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,p ;
	cin >> n >> p ;
	string s ; cin >> s ;
	if(p==2||p==5){
		ll ans = 0 ;
		for(int i=0;i<n;i++){
			if((s.at(i)-'0')%p==0){
				ans += i+1 ;
			}
		}
		cout << ans << endl ;
		return 0 ;
	}
	vll rem(n+1,0) ;
	vll cnt(p,0) ;
	cnt.at(0) = 1 ;
	ll ten = 1 ;
	ll ans = 0 ;
	for(int i=n-1;i>=0;i--){
		ll sub = s.at(i)-'0' ;
		sub = sub*ten%p ;
		sub = (sub+rem.at(i+1))%p ;
		ans += cnt.at(sub) ;
		cnt.at(sub)++ ;
		rem.at(i) = sub ;
		ten = ten*10%p ;
//		cout << sub << endl ;
	}
	cout << ans << endl ;
}
