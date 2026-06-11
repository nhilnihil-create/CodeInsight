#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int x,n;
  cin >> x >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  
  map<int,bool> mp;
  REP(i,300) mp[i-100] = true;
  
  for( int x:p ){
    if(mp.count(x)){
      mp[x] = false;
    }
  }
  
  int ans = 0;
  int m = 500;
  REP(i,300){
    if(mp[i-100] == true){
      if(abs(x - (i-100)) < m){
        m = abs(x - (i-100));
        ans = (i-100);
      }
    }
  }
  
  cout << ans << endl;
  
  
}