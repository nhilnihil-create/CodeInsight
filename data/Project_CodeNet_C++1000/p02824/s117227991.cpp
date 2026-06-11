#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std ;
const int N = 1e5+5 ;
long long a[N],b[N],n,m,v,p ; 
inline bool check(long long mid,long long n,long long m,long long v,long long p){
	memcpy(b,a,sizeof a) ;
	for(int i = mid ; i <= n ; i++){ if(!v) break ; b[i] += m ;	v-- ; }
	for(int i = 1 ; i < p ; i++){ if(!v) break ; b[i] += m ; v-- ; }
	long long rest = v*m ;
	if(rest == 0) return b[mid] >= b[p] ;
	for(int i = p ; i < mid ; i++){
		if(b[i] - b[mid] > 0) return false ;
		rest -= min(m,b[mid]-b[i]) ;
		if(rest <= 0) break ; 
	}
	if(rest > 0) return 0 ;
	return true ; 
}
int main(){
//	freopen("in.txt","r",stdin) ;
	ios::sync_with_stdio(false) ;
	cin >> n >> m >> v >> p ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	sort(a+1,a+n+1,greater<long long>()) ;
	int l = p,r = n ;
	while(l < r){
		int mid = (l+r+1)>>1 ;
		if(check(mid,n,m,v,p)) l = mid ;
		else r = mid-1 ; 
	}
	cout << l << endl ; 
	return 0 ; 
}