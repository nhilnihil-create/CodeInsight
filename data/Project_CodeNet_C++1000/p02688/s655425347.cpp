#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  int d;
  cin >> n >> k;
  vector<int> have(n, 0);
  for(int i = 0; i < k; i++) {
    cin >> d;
    vector<int> sweet(d);
    for(int j = 0; j < d; j++) {
      cin >> sweet.at(j);
      have.at(sweet.at(j)-1)++;
    }
  }
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(have.at(i) == 0) {
      count ++;
    }
  }
  cout << count << endl;
}