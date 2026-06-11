#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N; cin >> N;
  for(int i = (100 * N + 107) / 108; i < (100 * N + 207) / 108; i++) {
    cout << i << endl;
    return 0;
  }
  cout << ":(" << endl;
}
