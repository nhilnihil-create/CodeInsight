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
//#define all(v) v.begin(),v.end()
ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

vll three ;
string s ;
ll mx = 0 ;

ll DFS(ll d){
	if(d==mx) return three.at(d-1) ;
	if(d==2){
		if(s.at(1)=='1') return 5 ;
		else return (s.at(0)=='1'?3:1) ;
	}
	if(s.at(d-1)=='1') return (three.at(d-2)+2*DFS(d-1))%mod ;
	else return DFS(d-1) ;
}

int main(){
	cin >> s ;
	ll n = s.size() ;
	three.emplace_back(3) ;
	for(int i=1;i<n;i++) three.emplace_back(three.at(three.size()-1)*3%mod) ;
	ll ans = 0 ;
	for(int i=n-1;i>=0;i--){
		if(s.at(i)=='1') mx++ ;
		else break ;
	}
	reverse(s.begin(),s.end()) ;
	cout << DFS(n) << endl ;
}

