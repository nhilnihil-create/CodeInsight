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
using vvll = vector<vll> ;
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
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,m ;
	cin >> n >> m ;
	vll s(n),t(m) ;
	for(auto &i:s) cin >> i ;
	for(auto &i:t) cin >> i ;
	vvll dp(n+2,vll(m+2,0)) ;
//	dp.at(0).at(0) = 1 ;
	for(int i=0;i<=n;i++) dp.at(i).at(0) = 1 ;
	for(int j=0;j<=m;j++) dp.at(0).at(j) = 1 ;
	vll last(1e5+1,-1) ;
	for(int i=1;i<=n;i++){
//		vll sub(1e5+1,m+1) ;
		last.at(s.at(i-1)) = i ;
		for(int j=1;j<=m;j++){
			dp.at(i).at(j) = dp.at(i).at(j-1) ;
			if(last.at(t.at(j-1))!=-1) dp.at(i).at(j) += dp.at(last.at(t.at(j-1))-1).at(j) ;
//			if(s.at(i-1)==t.at(j-1)) dp.at(i).at(j) += dp.at(i-1).at(j-1) ;
			dp.at(i).at(j) %= mod ;
//			sub.at(t.at(j-1)) = j ;
		}
//		last.at(s.at(i-1)) = i ;
	}
	cout << dp.at(n).at(m) << endl ;
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=m;j++) cout << dp.at(i).at(j) << " " ;
//		cout << endl ;
//	}
}
