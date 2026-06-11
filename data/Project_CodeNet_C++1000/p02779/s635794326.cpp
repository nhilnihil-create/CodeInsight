#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N; cin >> N;
  set<int> A;
  int a[N];

  for(int i=1; i<=N; i++) {
    cin >> a[i];
    A.insert(a[i]);
    if(A.size() < i) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}