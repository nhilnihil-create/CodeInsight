#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N,M;
  cin >> N >> M;
  
  vector<long long>A(N);
  vector<long long>B(N*35);
  long long sum = 0;
  int L = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
    for (int j = 0; j < 35; j++) {
      B.at(L) = A.at(i);
      L++;
      A.at(i) /= 2;
      if (A.at(i) == 0){
        break;
      }
    }
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  
  long long ans = sum;
  for (int i = 0; i < min(M,(N*35)); i++) {
    ans -= (B.at(i)+1)/2;
  }
  cout << ans << endl;
}
   