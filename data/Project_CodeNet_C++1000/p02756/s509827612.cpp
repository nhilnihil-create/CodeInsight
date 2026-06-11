#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  string s; int q;
  cin >>s >>q;
  deque<char> ds(s.size()); 
  rep(i,s.size()) ds[i]=s[i];
  int F = 0;
  rep(i,q){
    int t; cin >>t;
    if(t==1) F = 1-F;
    else {
      int f; char c;
      cin >>f >>c; f--;
      if(F) f = 1-f;
      if(f==0) ds.push_front(c);
      else ds.push_back(c);
    }
  }
  if(F) reverse(ds.begin(), ds.end());
  for(auto c:ds) cout << c;
  cout << endl;
  return 0;
}