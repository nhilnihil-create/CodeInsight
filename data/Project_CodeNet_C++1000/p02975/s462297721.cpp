#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
#include <map>
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

void yorn(bool a){if(a) cout << "Yes" ; else cout << "No" ; cout << endl ;}
//string yorn(bool a){if(a) return"Yes" ; return "No" ;}
//string YorN(bool a){if(a) return"YES" ; return "NO" ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

int main(){
	ll n ; cin >> n ;
	map<ll,ll> s ;
	vll num(0) ;
	for(int i=0;i<n;i++){
		ll a ; cin >> a ;
		if(s.count(a)) s[a]++ ;
		else{
			s[a] = 1 ;
			num.push_back(a) ;
		}
	}
	if(s.size()==1){
		yorn(num.at(0)==0) ;
		return 0 ;
	}
	if(s.size()==2){
		yorn(n%3==0&&s.count(0)&&s[0]==n/3) ;
		return 0 ;
	}
	if(s.size()==3){
		if(n%3!=0) yorn(0) ;
		else yorn(s[num.at(0)]==s[num.at(1)]&&s[num.at(1)]==s[num.at(2)]&&(num.at(0)^num.at(1)^num.at(2))==0) ;
		return 0;
	}
	yorn(0) ;
}
