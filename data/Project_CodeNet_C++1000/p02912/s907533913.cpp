#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main (){
	int n, m ;
	cin >> n >> m ;
	multiset<int> s ; 
	ll tot = 0 ;
	rep(i, n) {
		int a ;
		cin >> a ;
		tot += a ;
		s.insert(a) ;
	}
	rep(i, m){
		if(*s.rbegin() == 0) break ;
		else {
			int k = *s.rbegin() ;
			s.erase(s.find(k)) ;
			tot -= k - k/2 ;
			k /= 2 ;
			s.insert(k) ;
		}
	}
	if(tot <= 0){
		cout << 0 << endl ;
	}
	else {
		cout << tot << endl ;
	}
}