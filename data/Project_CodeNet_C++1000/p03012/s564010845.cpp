#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec.at(i);
  }
  
  vector<int> ans(n);

  int up = 0;
  int down = 0;

  
  for(int i = 0; i < n; i++){
    down += vec.at(i);
  }
  
  for(int i = 0; i < n; i++){
    up += vec.at(i);
    down -= vec.at(i);
    ans.at(i) = abs(up - down);
  }
  
  sort(ans.begin(), ans.end());
  
  cout << ans.at(0) << endl;
}