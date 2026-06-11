#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> v(n);
  int i;
  for(i=0;i<n;i++) cin >> p[i];
  for(i=0;i<n;i++) v[i]=p[i];
  sort(p.begin(),p.end());
  int cnt=0;
  for(i=0;i<n;i++){
    if(v[i]!=p[i]) cnt++;
  }
  if(cnt<=2) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}