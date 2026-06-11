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
using vvll = vector<vll> ;
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
//void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
//void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

int main(){
	ll n,k ;
	cin >> n >> k ;
	map<ll,ll> m ;
	vll a(n),sum(n+1,0) ;
	for(int i=0;i<n;i++){
		cin >> a.at(i) ;
		sum.at(i+1) = sum.at(i)+a.at(i)-1 ;
		sum.at(i+1) %= k ;
	}
	ll ans = 0 ;
	for(int i=0;i<=n;i++){
		if(i<k){
			ans += m[sum.at(i)] ;
			m[sum.at(i)]++ ;
		}else{
			m[sum.at(i-k)]-- ;
			ans += m[sum.at(i)] ;
			m[sum.at(i)]++ ;
		}
	}
//	for(int i=0;i<n+1;i++) cout << sum.at(i) << (i==n?'\n':' ') ;
	cout << ans << endl ;
}
