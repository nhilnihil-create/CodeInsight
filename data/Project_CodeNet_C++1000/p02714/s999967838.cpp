#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll mod = 998244353;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  set<int> r, g, b;
  
   rep(i, s.size()){
     if(s[i]=='R') r.insert(i);
     if(s[i]=='G') g.insert(i);
     if(s[i]=='B') b.insert(i);
   }
  ll uns = 0;
  for(int p : r){
    for(int q : g){
      int u, v, w;
      u = v = w = 0;
      u = 2*p - q;
      v = 2*q - p;
      if((p+q)%2==0) w = (p+q)/2;       
      if(b.count(u)) uns++;
      if(b.count(v)) uns++;
      if((p+q)%2==0 && b.count(w)) uns++;      
   }
  }
  
   ll ans = r.size()*g.size()*b.size() - uns;
   cout << ans << endl;   
  
  
  return 0;
}
