#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, n;
  cin >> a >> n;
  vector<int> vec(n);
  for(int i = 0;i < n;i++) {
    cin >> vec.at(i);
    a = a - vec.at(i);
  }
  if(a <= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
