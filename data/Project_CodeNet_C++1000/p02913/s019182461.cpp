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
	int n ; cin >> n ;
	string s ; cin >> s ;
	int ans = 0 ;
	for(int i=0;i<n;i++){
		vll cnt(n,0) ;
		cnt.at(i) = n-i ;
		int p=i+1,j=0 ;
		while(p<n){
			while(p+j<n&&s.at(p+j)==s.at(i+j)) j++ ;
			cnt.at(p) = j ;
			if(j==0){
				p++ ;
				continue ;
			}
			int k = 1 ;
			while(k<j&&k+cnt.at(i+k)<j){
				cnt.at(p+k) = cnt.at(i+k) ;
				k++ ;
			}
			p += k ;
			j -= k ;
		}
		for(int j=i;j<n;j++){
			ans = max(ans,min(cnt.at(j),j-i)) ;
//			cout << cnt.at(j) << (j==n-1?'\n':' ') ;
		}
	}
	cout << ans << endl ;
}
