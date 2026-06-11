#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
using namespace std;

vector<int> buf;
vector<int> G[10000000] ;
int k = 0 ;
void dfs(int i, const int size, const int range_start, const int range_end)
{
    if ( i-1 == size ) {
        for(int i = 1 ; i <= size ; ++i){
          	G[k].push_back(buf[i]) ;
        }
        k++ ;
      return ;
    }
    else{
        for(int j = buf[i-1] ; j <= range_end ; ++j){
            buf[i] = j ;
            dfs(i + 1, size, range_start, range_end);
        }
    }
}

int main(void)
{
  	int n , m , q ;
  	cin >> n >> m >> q ;
  	int a[q] , b[q] ,c[q] , d[q] ;
  	rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i] ;
    int size = n ;
    int range_start = 1 ;
    int range_end = m  ;
    buf.resize(size+1)  ;
    buf[0] = 1 ;
  	ll ans = 0 ;
    dfs(1, size, range_start, range_end);
	for(int i = 0 ; i < k ; i++ ){
      
      vector<int> A(size) ;
      int j = 0 ;
      for( auto p : G[i] ) A[j++] = p ;
      ll tem =  0 ;
      rep(l,q) if( A[b[l]-1] - A[a[l]-1] == c[l] ) tem += d[l] ; 
      ans = max(tem,ans) ;
      
      //for( auto p : G[i] ) cout << p << ' ' ;
      //cout << endl;
    }
  	cout << ans << endl;
}
