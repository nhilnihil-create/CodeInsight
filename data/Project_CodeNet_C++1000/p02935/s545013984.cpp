#include<bits/stdc++.h>
using namespace std;
int main() {
  int n = 0; cin >> n;
  vector<double> vi(n);
  for(double &c : vi) {
    cin >> c;
  }
  sort(vi.begin(), vi.end());
  vector<double> sum(n -1, 0);
  for(int i = 0; i < n -1; i++) {
    if(i == 0) {
      sum.at(0) = (vi.at(0) + vi.at(1)) /2;
    }
    else {
      sum.at(i) = (sum.at(i -1) + vi.at(i +1)) /2;
    }
  }
  cout << sum.at(n -2) << endl;
}