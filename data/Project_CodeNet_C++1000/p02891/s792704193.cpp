#include <iostream>
//#include <iomanip>
#include <string>
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
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	string s ; cin >> s ;
	ll k ; cin >> k ;
	bool ok = true ;
	for(int i=0;i<s.size();i++) ok &= (s.at(i)==s.at(0)) ;
	if(ok){
		cout << (s.size()*k)/2  << endl ;
		return 0 ;
	}
	ll f=0,b=0 ;
	for(int i=0;i<s.size();i++){
		if(s.at(i)!=s.at(0)) break ;
		f++ ;
	}
	for(int i=s.size()-1;i>=0;i--){
		if(s.at(i)!=s.at(s.size()-1)) break ;
		b++ ;
	}
	ll ans = 0 ;
	for(int i=f;i<s.size()-b;i++){
		if(s.at(i)==s.at(i+1)){
			ans++ ;
			s.at(i+1) = '?' ;
		}
	}
	if(s.at(0)==s.at(s.size()-1)) ans = ans*k+f/2+b/2+(f+b)/2*(k-1) ;
	else ans = (ans+f/2+b/2)*k ;
	cout << ans << endl ;
}
