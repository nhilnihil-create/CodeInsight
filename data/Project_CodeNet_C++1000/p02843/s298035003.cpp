#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int x ; 
  cin >> x ; 
  if( x >= 2000 ){
    cout << 1 <<endl ; 
    return 0 ;
  }
  
  else{ 
    rep(i,20){
      rep(j,20){
        rep(k,20){
          rep(l,20){
            rep(m,20){
              rep(n,20){
                if( x == 100*i + 101*j + 102*k + 103*l + 104*m + 105*n ) {
                  cout << 1 <<endl ; ;
                  return 0 ;
                }
              }
            }
          }
        }
      }
    }
  }
 
  
  cout << 0 <<endl ;
  
                  
                  
                
    

}
