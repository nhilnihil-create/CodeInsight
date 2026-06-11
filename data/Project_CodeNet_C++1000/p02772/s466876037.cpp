#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string ans;
  vector<int> A(N);
  bool a = true;
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) % 2 == 0 && A.at(i) % 3 != 0 && A.at(i) % 5 != 0){
      a = false;
    }
  }
  if(a == true) {
    ans = "APPROVED";
  }
  else {
    ans = "DENIED";
  }
  cout << ans << endl;
}