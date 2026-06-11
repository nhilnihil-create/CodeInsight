#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, c; cin >> n;
  map<int, int> di;
  vector<int> disort(n);
  int min = 100000, max = 0;
  for(int i = 0; i < n; i++) {
    cin >> c;
    disort.at(i) = c;
    if(c < min) {
      min = c;
    }
    if(c > max) {
      max = c;
    }
    if(di.count(c)) {
      di.at(c)++;
    }
    else {
      di[c] = 1;
    }
  }
  sort(disort.begin(), disort.end());
  int k = disort.at(n /2 -1) +1;
  if(disort.at(n /2) == k -1) {
    cout << 0 << endl;
  }
  else {
    int count = 1;
    while(disort.at(n /2) != k) {
      k++;
      count++;
    }
    cout << count << endl;
  }
}