#include<iostream>
using namespace std;

#include <vector>
#include <algorithm>
int main(){
  int n,k; cin >> n >> k;
  vector<int> p(n);
  for(int i=0; i<n; i++) cin >> p[i];
  sort(p.begin(),p.end());
  int ans = 0;
  for(int i=0; i<k; i++) ans += p[i];
  cout << ans << endl;
}