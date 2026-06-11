#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int,int> mode;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    mode[x] += 1;
  }
  bool bl = false;
  bool b = true;
  int k = mode.size();
  if (k == 1 && mode[0] == N) bl = true;
  if (k == 2 && double(mode[0]) == N/3.0) bl = true; 
  if (k == 3) {
    vector<int> v;
    for (auto m : mode) {
      v.push_back(m.first);
      if (m.second != N/3) b = false;
    }
    bitset<32> A(v[0]);
    bitset<32> B(v[1]);
    bitset<32> C(v[2]);
    if ((A^B) == C) bl = true;
  }
  cout << (bl & b ? "Yes" : "No") << endl;
}