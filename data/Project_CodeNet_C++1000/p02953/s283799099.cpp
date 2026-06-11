#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  bool ok = true;
  int max = v[0]-1;
  if(max<0) max = 0;
  for(int i=1; i<n; i++) {
    if(max<v[i]) v[i]--;
    if(max>v[i]) {ok = false; break;}
    if(v[i]>max) max = v[i];
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}