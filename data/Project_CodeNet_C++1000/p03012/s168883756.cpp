#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i,n){
    cin >> vec[i];
  }
  set<int> S;
  rep(i,n-1){
    int s = 0, t = 0;
    rep(j,i+1){
      s += vec[j];
    }
    rep(k,n-i-1){
      t += vec[n-1-k];
    }
   
    S.insert(max(s,t) - min(s,t));
  }
  cout << *begin(S);
  
    
  return 0;
}