#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, c; cin >> n;
  vector<pair<int, int>> ai(n);
  for(int i = 0; i < n; i++) {
    cin >> c;
    ai.at(i).first = c;
    ai.at(i).second = i+1;
  }
  sort(ai.begin(), ai.end());
  for(pair<int, int> b : ai) {
    cout << b.second << ' ';
  }
  cout << endl;
}