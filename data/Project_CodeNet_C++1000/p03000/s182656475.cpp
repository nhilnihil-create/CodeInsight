#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  for (int i=0 ; i<n ; i++)
    cin >> l.at(i);
  
  int d = 0, ans = 1;
  for (int i=0 ; i<n ; i++){
    d += l.at(i);
    if (d > x)
      break;
    ans++;
  }
  
  cout << ans << endl;
}