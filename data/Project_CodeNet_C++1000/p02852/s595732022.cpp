#include <iostream>
//#include <iomanip>
#include <string>
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

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n,m ;
	cin >> n >> m ;
	string s ;
	cin >> s ;
	reverse(s.begin(),s.end()) ;
	for(int i=0;i<m;i++) s += '1' ;
	vll ans ;
	ll pos = 0 ;
	while(pos!=n){
		bool ok = false ;
		for(int i=m;i>0;i--){
			if(s.at(pos+i)=='0'){
				ok = true ;
				pos += i ;
				ans.push_back(i) ;
				break ;
			}
		}
		if(!ok){
			cout << -1 << endl ;
			return 0 ;
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout << ans.at(i) ;
		if(i==0) cout << endl ;
		else cout << " " ;
	}
}
