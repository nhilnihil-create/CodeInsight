#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0;i < n;i++){
    cin >> p[i];
  }
  int c = 0;
  
  for (int i = 0;i < n;i++){
    if (p[i] != i+1){
      c++;
    }
  }
  
  if (c == 0 || c == 2){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}