#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  string t;
  cin >> t;
  int n = t.size();
  
  rep(i, n-1){
    if (t[i] == '?') cout << 'D';
    else cout << (t[i]);        
  }
  if (t[n-1] == '?') cout << 'D' << endl;
  else cout << (t[n-1]) << endl;        
  
return 0;
}