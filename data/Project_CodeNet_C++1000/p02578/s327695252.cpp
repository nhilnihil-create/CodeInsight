#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> As;

int main() {
  int N;
  cin >> N;
  
  int A;
  for (int i = 0; i < N; i++) {
    cin >> A;
    As.push_back(A);
  }
  
  ll tmp, ans = 0;
  for (int i = 0; i < N-1; i++) {
    tmp = As[i+1] - As[i];
    if (tmp < 0) {
      ans -= tmp;
      As[i+1] -= tmp;
    }
  }
  cout << ans << endl;
  
  return 0;
}