#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  LL N;
  cin >> N;
  //vector<LL> a(N);
  unordered_map<LL, LL> m;
  for (int i=0; i<N; i++) {
    LL a;
    cin >> a;
    m[a]++;
  }
  
  bool flag = true;
  if (m.size() > 3) {
    flag = false;
  } else if (m.size() == 3) {
    LL t = 0;
    for (auto a : m) {
      t ^= a.first;
      if (a.second != N / 3) {
        flag = false;
      }
    }
    if (t != 0) {
      flag = false;
    }
  } else if (m.size() == 2) {
    for (auto a : m) {
      if (a.first == 0) {
        if (a.second != N / 3) {
          flag = false;
        }
      }
    }
  } else {
    for (auto a : m) {
      if (a.first != 0) flag = false;
    }
  }
  
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}