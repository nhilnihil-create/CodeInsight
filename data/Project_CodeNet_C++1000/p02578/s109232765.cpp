#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  long long same;
  same = 0;
  cin >> n;
  vector<int> tall(n);
  for(i=0;i<n;i++) {
    cin >> tall.at(i);
  }
  for(i=0;i<n-1;i++) {
    if(tall.at(i) > tall.at(i+1)) {
      same += tall.at(i) - tall.at(i+1);
      tall.at(i+1) = tall.at(i);
    }
  }
  cout << same << endl;
  return 0;
}