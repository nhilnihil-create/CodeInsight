#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  
  if(n < 3){
    cout << 0 << endl;
    return 0;
  }
  
  ll r=0, g=0, b=0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'R') r++;
    if(s[i] == 'G') g++;
    if(s[i] == 'B') b++;
  }
  ll ans = r*g*b;
  
  for(int j = 0; j < n; j++){
    for(int i = 0; i < j; i++){
      int k = j+j-i;
      if(k < n){
        if(s.at(i) != s.at(j) && s.at(j) != s.at(k) && s.at(k) != s.at(i)) ans--;
      }
    }
  }
  
  cout << ans << endl; 
  return 0;
}
