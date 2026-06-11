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
  vector<int> d(n) ;
  rep(i,n) cin >> d.at(i) ;
  sort(all(d)) ;
  int ans = 0 ;
  
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      for(int k=j+1;k<n;k++){
        if(d.at(i) != d.at(j) && d.at(j)!=d.at(k)){
          if(d.at(k) < d.at(i) + d.at(j) ) ans ++ ;
        }
      }
    }
  }
  
  cout <<ans ;
  
}
