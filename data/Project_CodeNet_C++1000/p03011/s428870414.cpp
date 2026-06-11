#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> list(3);
  for (int i=0; i<3; i++) {
    int a;
    cin >> a;
    list.at(i) = a;
  }
  sort(list.begin(),list.end());
  cout << list.at(0)+list.at(1) << endl;
}