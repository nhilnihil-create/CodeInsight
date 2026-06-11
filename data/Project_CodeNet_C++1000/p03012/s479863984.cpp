#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  int ans = 1000;
  int s1 = 0,s2 = 0;
  vector<int> w(n);
  for(int i = 0; i < n; i++)
    cin >> w.at(i);
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j <= i)
        s1 += w.at(j);
      else
        s2 += w.at(j);
    }
    if(ans > abs(s1-s2)) ans = abs(s1-s2);
    
    s1 = 0;
    s2 = 0;
  }
  
  cout << ans;
  
}
