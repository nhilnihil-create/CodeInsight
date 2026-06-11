#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> ra(a), ga(b), wa(c);
  for(int i=0; i<a; ++i) cin >> ra[i];
  for(int i=0; i<b; ++i) cin >> ga[i];
  for(int i=0; i<c; ++i) cin >> wa[i];
  sort(ra.begin(),ra.end());
  reverse(ra.begin(),ra.end());
  sort(ga.begin(),ga.end());
  reverse(ga.begin(),ga.end());
  for(int i=0; i<x; ++i) wa.push_back(ra[i]);
  for(int i=0; i<y; ++i) wa.push_back(ga[i]);
  sort(wa.begin(),wa.end());
  reverse(wa.begin(),wa.end());
  long long ans = 0;
  for(int i=0; i<x+y; ++i) ans += wa[i];
  cout << ans << endl;
}