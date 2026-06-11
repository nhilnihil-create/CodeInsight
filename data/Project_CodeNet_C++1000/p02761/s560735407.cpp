#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m);
  vector<char> c(m);
  for (int i = 0; i < m; i++){
    cin >> s.at(i) >> c.at(i);
  }
  int ans = -1;
  
  if (n == 1){
    for (int i = 0; i < 10;i++){
      string x = to_string(i);
      bool z = true;
      for (int j = 0; j < m; j++){
        if (x.at(s.at(j) - 1) != c.at(j)){
          z = false;
        }
      }
      if (z){
        ans = i;
        break;
      }
    }
  }
  
  if (n == 2){
    for (int i = 10; i < 100;i++){
      string x = to_string(i);
      bool z = true;
      for (int j = 0; j < m; j++){
        if (x.at(s.at(j) - 1) != c.at(j)){
          z = false;
        }
      }
      if (z){
        ans = i;
        break;
      }
    }
  }
  
  if (n == 3){
    for (int i = 100; i < 1000;i++){
      string x = to_string(i);
      bool z = true;
      for (int j = 0; j < m; j++){
        if (x.at(s.at(j) - 1) != c.at(j)){
          z = false;
        }
      }
      if (z){
        ans = i;
        break;
      }
    }
  }
  
  cout << ans << endl;
}