#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  map<int,int> map;
  for (int i =0; i<N; i++) {
    int a; cin >> a; A.at(i) = a;
    map[a] = i;
  }
  for (auto p : map) {
    int x = p.second + 1;
    cout << x << " ";
  }
  cout << endl;
}