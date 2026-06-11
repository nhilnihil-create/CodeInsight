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

ll ans,k ;

void BFS(vvll &g,vll &used,int n,queue<int> &q){
	used.at(n) = 1 ;
	int cnt = 0 ;
	for(int i=0;i<g.at(n).size();i++){
		if(!used.at(g.at(n).at(i))){
			ans = ans*(k-2-cnt)%mod ;
			q.push(g.at(n).at(i)) ;
			cnt++ ;
		}
	}
	if(q.empty()) return ;
	n = q.front() ;
	q.pop() ;
	BFS(g,used,n,q) ;
}

int main(){
	ll n ;
	cin >> n >> k ;
	if(n==1){
		cout << k << endl ;
		return 0 ;
	}
	vvll g(n,vll(0)) ;
	for(int i=0;i<n-1;i++){
		int a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		g.at(a).emplace_back(b) ;
		g.at(b).emplace_back(a) ;
	}
	vll used(n,0) ;
	ans = k ;
	queue<int> q ;
	used.at(0) = 1 ;
	for(int i=0;i<g.at(0).size();i++){
		ans = ans*(k-1-i)%mod ;
		q.push(g.at(0).at(i)) ;
	}
	int s = q.front() ;
	q.pop() ;
	BFS(g,used,s,q) ;
	cout << ans << endl ;
}

