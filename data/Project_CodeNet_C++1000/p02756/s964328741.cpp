#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  deque<char> d;
  for(int i=0;i<s.size();i++){
    d.push_back((char)s.at(i));
  }
  
  int q;
  cin >> q;
  bool flip = false;
  
  for(int i=0;i<q;i++){
    int t;
    cin >> t;
    if(t==1) {
      flip = !flip;
    }else{
      int f;
      char c;
      cin >> f >> c;
      if(flip) f = 3-f;
      if(f == 1){
        d.push_front(c);
      }else{
        d.push_back(c);
      }
    }
  }
  
  string ans="";
  for(auto c : d){
    ans += c;
  }
  if(flip){
    reverse(ans.begin(),ans.end());
  }
  
  cout << ans << endl;
  
  return(0);
}