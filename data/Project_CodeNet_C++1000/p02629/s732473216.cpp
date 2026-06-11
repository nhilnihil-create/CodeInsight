#include <bits/stdc++.h>
using namespace std;

int64_t sum(int64_t x) {
  int64_t S=0;
  for (int64_t i=0; i<=x; i++) {
    S += pow(26, i);
  }
  return S;
}

int main() {
  int64_t N;
  cin >> N;
  char C;
  int64_t ccc, keta=0;
  for (int i=0; i<11; i++) {
    if (N >= sum(i) && N < sum(i+1)) {
      keta = i+1;
    }
  }
  //cout << keta << endl;
  
  vector<char> name(keta);
  N -= (sum(keta-1));
  
  for (int i=0; i<keta; i++) {
    ccc = N - N / 26 * 26 + 97;
    N = N/26;
    C = (char)ccc;
    name.at(i) = C;
  }
  
  for (int i = keta-1; i>=0; i--) {
    cout << name.at(i);
  }
  cout << endl;
}