#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int n; cin >> n;
  vector<string> s(n);
  vector<int>    t(n);
  
  for(int i=0; i<n; i++){
    cin >> s[i] >> t[i];
  }
  
  string x; cin >> x;
  
  int fall;
  for(int i=0; i<n; i++){
    if(s[i].size()==x.size() && s[i]==x){
      fall = i;
      break;
    }
  }
  
  int ans = 0;
  
  for(int i=fall+1; i<n; i++){
    ans += t[i];
  }
  
  cout << ans << endl;
}