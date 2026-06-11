#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  int i;
  vector<int> h(n);
  for(i=0;i<n;i++) cin >> h[i];
  sort(h.begin(),h.end());
  long long cnt = 0;
  for(i=0;i<n-k;i++) cnt += h[i];
  cout << cnt << "\n";
  return 0;
}