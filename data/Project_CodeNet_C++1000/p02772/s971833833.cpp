#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int c = 0;
  for(int i = 0;i < N;++i) {
    cin >> vec.at(i);
  }
  bool flg;
  for(int i = 0;i < N;++i) {
    if(vec.at(i) % 2 == 0) {
      if(vec.at(i) % 3 == 0 || vec.at(i) % 5 == 0) {
        flg = true;
      } else {
        flg = false;
        break;
      }
    }
  }
  if(flg) {
    cout << "APPROVED" << endl;
  } else {
    cout << "DENIED" << endl;
  }
}