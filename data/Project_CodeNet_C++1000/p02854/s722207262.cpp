#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long sum = 0;
  vector<long long>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  
  long long half = 0;
  long long d1,d2;
  for (int i = 0; i < N; i++) {
    half += A.at(i);
    if (half*2 == sum){
      cout << 0 << endl;
      return 0;
    }
    else if (half*2 > sum){
      d1 = half*2 - sum;
      d2 = sum - half*2 + A.at(i)*2;
      cout << min(d1,d2) << endl;
      return 0;
    }
  }
}
      