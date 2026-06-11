#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  double ans =0.0, A;
  cin >> N;
  
  for(int i=0; i<N; i++) {
    cin >> A;
    ans += 1.0 / A;
  }
 cout << 1.0 / ans << endl;
}
