#include <bits/stdc++.h>
using namespace std;

int main() {

  long long N, A, B;
  cin >> N >> A >> B;
  
  long long ans;
  ans = N / (A + B) * A + min( N % (A + B), A);
  
  cout << ans << endl;

}