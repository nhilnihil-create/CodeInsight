#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b, m; cin >> a >> b >> m;
  vector<int> ai(a), bj(b), aisorted(a), bjsorted(b);
  for(int i = 0; i < a; i++) {
    cin >> ai.at(i);
    aisorted.at(i) = ai.at(i);
  }
  for(int i = 0; i < b; i++) {
    cin >> bj.at(i);
    bjsorted.at(i) = bj.at(i);
  }
  sort(aisorted.begin(), aisorted.end());
  sort(bjsorted.begin(), bjsorted.end());
  
  vector<int> x(m), y(m), c(m);
  for(int i = 0; i < m; i++) {
    cin >> x.at(i) >> y.at(i) >> c.at(i);
  }
  
  set<int> allmin;
  allmin.insert(aisorted.at(0) + bjsorted.at(0));
  for(int i = 0; i < m; i++) {
    int eachmin;
    eachmin = ai.at(x.at(i)-1) + bj.at(y.at(i)-1) - c.at(i);
    allmin.insert(eachmin);
  }
  cout << *begin(allmin) << endl;
}