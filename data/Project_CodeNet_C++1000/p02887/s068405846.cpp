#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, c=1;
  string S;
  cin >> N >> S;
  for (int i=0; i<N-1; i++) {
    if (S[i]!=S[i+1]) {c++;}
  }
  cout << c << endl;
}