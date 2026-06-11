 #include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> A(n);
  double inv;
  for(int i = 0; i < n; ++i){ 
    cin >> A[i];
    inv += 1.0 / A[i];
  }
  cout << 1/inv << endl;
}
