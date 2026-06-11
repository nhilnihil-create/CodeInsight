#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, k, q; cin >> n >> k >> q;
  vector<int> finalpoints(n, 0);
  int ai;
  for(int i = 0; i < q; i++) {
    cin >> ai;
    finalpoints.at(ai -1)++;
  }
  for(int i = 0; i < n; i++) {
    if(k -q + finalpoints.at(i) > 0) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}