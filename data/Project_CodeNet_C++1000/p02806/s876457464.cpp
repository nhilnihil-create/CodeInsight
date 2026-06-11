#include <bits/stdc++.h>
using namespace std;

int main() {
  bool j = false;
  int n, ans;
  
  cin >> n;
  string x;
  vector<int> t(n);
  vector<string> s(n);
  
  for (int i=0;i < n;i++){
    cin >> s.at(i) >> t.at(i);
  }
  cin >> x;
  
  for(int i = 0; i<n;i++){
    if(j){
      ans = ans + t.at(i);
    }
    if(s.at(i) == x){
      j = true;
    }
  }
  
  cout << ans << endl;
}
