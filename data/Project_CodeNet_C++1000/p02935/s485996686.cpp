#include <bits/stdc++.h>
using namespace std;
int power_2(int x) {
  int ans = 1;
  for(int i = 0; i < x; i++) {
    ans *= 2;
  }
  return ans;
}
int main() {
  int N;
  cin >> N;
  vector<long double> vec(N);
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  long double ans = 0;
  cout << setprecision(10);
  for(int i = 0; i < N; i++) {
    ans += vec.at(i);
    if(i != 0) {
      ans /= 2;
    }
  }
  cout << ans << endl;
}