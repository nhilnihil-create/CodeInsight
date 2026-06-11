#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<unsigned long> a(N);
  bitset<32> s(0uL);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    s ^= bitset<32>(a[i]);
  }

  for (int i = 0; i < N; i++) {
    cout << (s ^ bitset<32>(a[i])).to_ulong() << " ";
  }
  cout << endl;
}
