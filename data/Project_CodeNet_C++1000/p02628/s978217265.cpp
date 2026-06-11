#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
  cin >> n >> k;
   vector<int> anko(n);
 
  for (int i = 0; i < n; i++) {
    cin >> anko.at(i);
  }
  sort(anko.begin(), anko.end());
  int x = 0;
  for (int j = 0; j < k; j++) {
    x = x + anko.at(j);
  }
  cout << x << endl;
}
