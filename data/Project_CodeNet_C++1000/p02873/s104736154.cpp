#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int l = s.size();
  vector<int> a(l+1);
  int now = 0;
  for(int i = 0; i < l; i++){
    char c = s.at(i);
    if(c == '<'){
      a.at(i) = now++;
      a.at(i+1) = now;
    }
    else now = 0;
  }
  now = 0;
  for(int i = l-1; i >= 0; i--){
    char c = s.at(i);
    if(c == '<') now = 0;
    else{
      a.at(i+1) = max(a.at(i+1), now);
      now++;
      a.at(i) = max(a.at(i), now);
    }
  }
  
  long long ans = 0;
  for(auto k : a) ans += k;
  
  cout << ans << endl;
}