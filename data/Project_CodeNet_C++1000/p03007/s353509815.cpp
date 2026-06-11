#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto&& x:a)cin >> x;
  sort(a.begin(), a.end());
  vector<pair<int, int> > sol;
  for(int i=1;i<n-1;i++){
    if(a[i] > 0){
      sol.emplace_back(a[0], a[i]);
      a[0] -= a[i];
    }
    else{
      sol.emplace_back(a[n-1], a[i]);
      a[n-1] -= a[i];
    }
  }
  sol.emplace_back(a[n-1], a[0]);
  a[n-1] -= a[0];
  cout << a[n-1] << endl;
  for(auto&& x:sol)cout << x.first << " " << x.second << endl;
  return 0;
}