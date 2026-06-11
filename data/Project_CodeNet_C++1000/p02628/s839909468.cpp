#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n , k ; 
  cin >> n >> k ;
  vector<int> p(n) ; 
  rep(i,n) cin >> p.at(i) ;
  
  sort(all(p)) ;
  
  int ans = 0 ;
  rep(i,k){
    ans += p.at(i) ;
  }
  
  cout << ans ;
}
