#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  int n, k, c; cin >> n >> k >> c;
  string s; cin >> s;
  
  auto getPosition = [&](){
    vector<int> res;
  for(int i=0; i<n && res.size()<=k ;){
    if(s[i]=='x') i++;
    else{ res.push_back(i); i+= c+1;}
  }    
    return res;
  };
  
  vector<int> l, r;
  l = getPosition();
  reverse(s.begin(), s.end());
  r = getPosition();
  rep(i, r.size()) r[i] =n-1-r[i];
  reverse(r.begin(), r.end());

  rep(i, k){
    if(l[i] == r[i]) cout << l[i]+1 << endl;
  }
  
  return 0;
}