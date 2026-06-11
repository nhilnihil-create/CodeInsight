#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int x;
  vector<int> r;
  int t = 0;
  while(x) {
    cin >> x;
    if(x) {
      r.push_back(x);
      t++;
    }
  }
  for(int i = 0; i < t; i++) cout << "Case " << i + 1 << ": " << r.at(i) << endl;
}
