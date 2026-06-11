#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int h, n;
  cin >> h >> n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    vec.at(i) = x;
  }
  int ans = 0;
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  for(int i = 0; i < n; i++){
    h -= vec.at(i);
    if(h <= 0){
      ans = 1;
      break;
    }
  }
  
  if(ans == 1){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
  
  
  
  
  
}