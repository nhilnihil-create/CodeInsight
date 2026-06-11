#include <bits/stdc++.h>
using namespace std;

int main(){
  string a, b;
  cin >> a >> b;
  int ans = 0;
  for(int i = 0; i < (int)a.size(); ++i)
    if(a[i]!=b[i])
      ans++;
  cout << ans << '\n';
  return 0;
}