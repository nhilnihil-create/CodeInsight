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
#define all(v) v.begin(),v.end()
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
	ll n,t ;
	cin >> n >> t ;
	vll a(n),b(n) ;
	for(int i=0;i<n;i++) cin >> a.at(i) >> b.at(i) ;
	vvll dp1(n+1,vll(t,0)),dp2(n+1,vll(t,0)) ;
	for(int i=1;i<=n;i++){
		for(int j=0;j<t;j++){
			dp1.at(i).at(j) = dp1.at(i-1).at(j) ;
			if(j>=a.at(i-1)) dp1.at(i).at(j) = max(dp1.at(i).at(j),dp1.at(i-1).at(j-a.at(i-1))+b.at(i-1)) ;
		}
	}
	reverse(all(a)) ;
	reverse(all(b)) ;
	for(int i=1;i<=n;i++){
		for(int j=0;j<t;j++){
			dp2.at(i).at(j) = dp2.at(i-1).at(j) ;
			if(j>=a.at(i-1)) dp2.at(i).at(j) = max(dp2.at(i).at(j),dp2.at(i-1).at(j-a.at(i-1))+b.at(i-1)) ;
		}
	}
	ll ans = 0 ;
	reverse(all(a)) ;
	reverse(all(b)) ;
	for(int i=1;i<=n;i++){
		ll sub = 0 ;
		for(int j=0;j<t;j++){
			sub = max(sub,dp1.at(i-1).at(j)+dp2.at(n-i).at(t-1-j)) ;
		}
		ans = max(ans,sub+b.at(i-1)) ;
	}
	cout << ans << endl ;
}
