#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  long long all = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    all += a.at(i);
  }
  
  long long left = 0, cen;
  for(int i = 0; i < n; i++){
    left += a.at(i);
    cen = a.at(i);
    if(left >= all/2) break;
  }
  
  if(left == all/2) cout << 0 << endl;
  else cout << -abs(all-2*left+cen) + cen << endl;
}