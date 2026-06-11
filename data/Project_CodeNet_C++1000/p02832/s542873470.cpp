#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0;i < n;i++){
    cin >> a[i];
  }
  
  int c = 1;
  
  for (int i = 0;i < n;i++){
    if (a[i] == c){
      c++;
    }
  }
  
  if (c == 1){
    cout << -1 << endl;
  }
  else{
    cout << n - c + 1 << endl;
  }
}