#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<long long> p(a), q(b), r(c);
  for(int i = 0; i < a; i++) cin >> p.at(i);
  for(int i = 0; i < b; i++) cin >> q.at(i);
  for(int i = 0; i < c; i++) cin >> r.at(i);
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  sort(r.begin(), r.end());
  reverse(p.begin(), p.end());
  reverse(q.begin(), q.end());
  reverse(r.begin(), r.end());
  vector<long long> take(0);
  for(int i = 0; i < x; i++) take.push_back(p.at(i));
  for(int i = 0; i < y; i++) take.push_back(q.at(i));
  sort(take.begin(), take.end());
  for(int i = 0; i < min(x+y, c); i++) {
    if(take.at(i) >= r.at(i)) break;
    take.at(i) = r.at(i);
  }
  long long taste = 0;
  for(int i = 0; i < x+y; i++) taste += take.at(i);
  cout << taste << endl;
  cout << endl;
}