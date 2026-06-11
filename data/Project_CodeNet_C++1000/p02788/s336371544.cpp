#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
#include <utility>
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
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end()
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
	ll n,d,a ;
	cin >> n >> d >> a ;
	vector<pll> enemy(n) ;
	for(int i=0;i<n;i++) cin >> enemy.at(i).first >> enemy.at(i).second ;
	sort(all(enemy)) ;
	vll sum(n,0) ;
	ll ans = 0 ;
	for(int i=0;i<n;i++){
		if(i!=0) sum.at(i) = sum.at(i-1)+sum.at(i) ;
		if(sum.at(i)>=enemy.at(i).second) continue ;
		enemy.at(i).second -= sum.at(i) ;
		ll cnt = (enemy.at(i).second+a-1)/a ;
		ans += cnt ;
		sum.at(i) += cnt*a ;
		ll l,r,m ;
		l = i ;
		r = n ;
		while(l+1<r){
			m = (l+r)/2 ;
			if(enemy.at(m).first>enemy.at(i).first+2*d) r = m ;
			else l = m ;
		}
		if(r!=n) sum.at(r) -= cnt*a ;
	}
	cout << ans << endl ;
}
