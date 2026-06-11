#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
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

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<string> &a){sort(a.begin(),a.end()) ;}
void myrev(vll &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,m ;
	cin >> n >> m ;
	string r ; cin >> r ;
	vll ans ;
	string f ;
	for(int i=0;i<m;i++) f += '1' ;
	f += r ;
	r = f ;
	ll pos = n+m ;
	while(pos!=m){
		bool ok = false ;
		for(int i=m;i>0;i--){
			if(r.at(pos-i)=='0'){
				pos -= i ;
				ans.push_back(i) ;
				ok = true ;
				break ;
			}
		}
		if(!ok){
			cout << -1 << endl ;
			return 0 ;
		}
	}
	myrev(ans) ;
	for(int i=0;i<ans.size();i++){
		cout << ans.at(i) ;
		if(i==ans.size()-1) cout << endl ;
		else cout << " " ;
	}
}
