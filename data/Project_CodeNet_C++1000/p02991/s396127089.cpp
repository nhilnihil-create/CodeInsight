#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
#include <queue>
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
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}
//ld dis(ll a,ll b,ll c,ll d){return sqrt((a-c)*(a-c)+(b-d)*(b-d)) ;}

int main(){
	ll n,m ;
	cin >> n >> m ;
	vvll g(n*3,vll(0)) ;
	for(int i=0;i<m;i++){
		ll a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		g.at(a).emplace_back(n+b) ;
		g.at(n+a).emplace_back(n+n+b) ;
		g.at(n+n+a).emplace_back(b) ;
	}
	ll s,t ;
	cin >> s >> t ;
	s-- ; t-- ;
	vll cnt(n*3,INF);
	queue<ll> q ;
	cnt.at(s) = 0 ;
	q.push(s) ;
	while(!q.empty()){
		ll p = q.front() ;
		q.pop() ;
//		cout << p << endl ;
		for(int i=0;i<g.at(p).size();i++){
			if(cnt.at(g.at(p).at(i))>cnt.at(p)+1){
				cnt.at(g.at(p).at(i)) = cnt.at(p)+1 ;
				q.push(g.at(p).at(i)) ;
			}
		}
	}
	ll ans = cnt.at(t) ;
	cout << (ans==INF?-1:ans/3) << endl ;
//	for(int i=0;i<3;i++){
//		for(int j=0;j<n;j++) cout << cnt.at(n*i+j) << (j==n-1?'\n':' ') ;
//	}
}
