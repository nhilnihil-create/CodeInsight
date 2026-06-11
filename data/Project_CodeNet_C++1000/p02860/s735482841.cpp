#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  string s; cin >> s;
  if(n % 2 == 1){
    cout << "No" << endl;
    return 0;
  }
  int m = n / 2;
  for(int i=0; i<m; i++){
    if(s[i] != s[i+m]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}