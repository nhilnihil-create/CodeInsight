#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n ;
  cin >> n ; 
  int ans = 0 ;
  
  rep(i,n) {
    int c ; 
    cin >> c ; 
    if( i%2 == 0 && c%2 == 1) ans ++ ;
  }
  
  cout << ans ;


}
