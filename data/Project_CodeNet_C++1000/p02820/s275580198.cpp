#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,r,s,p;
  cin >> n >> k >> r >> s >> p;
  string t;
  cin >> t;
  string a(n, '0');
  for (int i = 0;i < n;i++){
    if (t[i] == 'r'){
      a[i] = 'p';
      }
    if (t[i] == 's'){
      a[i] = 'r';
      }
    if (t[i] == 'p'){
      a[i] = 's';
    }
  }
  string b(n, '0');
  int ans = 0;
  
  for (int i = 0;i < n;i++){
    if (i < k){
      if (t[i] == 'r'){
        ans += p;
        b[i] = 'p';
      }
      if (t[i] == 's'){
        ans += r;
        b[i] = 'r';
      }
      if (t[i] == 'p'){
        ans += s;
        b[i] = 's';
      }
    }
    else{
      if (t[i] == 'r' && b[i-k] != 'p'){
        ans += p;
        b[i] = 'p';
      }
      if (t[i] == 's' && b[i-k] != 'r'){
        ans += r;
        b[i] = 'r';
      }
      if (t[i] == 'p' && b[i-k] != 's'){
        ans += s;
        b[i] = 's';
      }
    }
  }
    
  cout << ans << endl;
}