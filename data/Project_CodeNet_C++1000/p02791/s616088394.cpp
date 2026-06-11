#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, count;
  cin >> n;
  count = 1;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p.at(i);
  }
  int min = p.at(0);
  for (int i = 1; i < n; i++) {
    if (min > p.at(i)) {
      min = p.at(i);
      count++;
    }
  }
  cout << count << endl;
}