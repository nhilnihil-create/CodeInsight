#include <bits/stdc++.h>
typedef long long ll; 
typedef long double ld ; 
using namespace std;

class DSU {

      public :
      vector<int> par ;  
      vector<int> r ; 
      int ans = 0 ; 
      DSU(int n) {
            par.assign(n+1,0) ; 
            r.assign(n+1,0) ; 
            for(int i = 0 ; i <= n ; ++i) {
                  par[i] = i ; 
                  r[i] = 1  ; 
            }
      }
      
      int get(int n) {
            return par[n] = (par[n] ==n ? n : get(par[n])) ; 
      }

      void set_union(int a, int b) {
            a = get(a) ; 
            b = get(b) ; 
            if(a == b) 
            	return ; 
            if(r[a] > r[b]) {
                  swap(a,b) ;  
            }
            par[b] = a ; 
            r[a] += r[b] ; 
            ans = max(ans , r[a]) ; 
            ans = max(ans , r[b]) ;  
      }
      
}; 


int main() {
	
	#ifndef ONLINE_JUDGE
  		freopen("input.txt","r",stdin);
  		freopen("output.txt","w",stdout);
  	#endif 
  	
  	int n , m ; 
  	cin >> n >> m ; 
  	DSU fr(n) ; 
  	int a, b ; 
  	while(m--) {
  		cin >> a >> b  ; 
  		fr.set_union(a,b) ; 
  	}
  	int ans = 0 ; 
  	for(int i = 1 ; i <= n ; ++i) 
  		ans = max(ans, fr.r[i]) ; 
  	cout << ans  << "\n" ; 

  	return 0 ; 
}