#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s; cin >>s;
  int n = s.size()+1;
  vector<int> a(n);
  rep(i,n){
    if(s[i]=='<'){
      a[i+1] = max(a[i+1], a[i]+1);
    }
  }
  for(int i = n-1; 0<=i; i--){
    if(s[i]=='>'){
      a[i] = max(a[i], a[i+1]+1);
    }
  }
  ll ans = 0;
  for(auto x : a){
    ans += x;
  }
  cout << ans << endl;
  return 0; 
}