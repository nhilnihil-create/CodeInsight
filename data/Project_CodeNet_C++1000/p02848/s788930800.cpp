#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  cin >> N >> S;

  for (int i = 0; i < S.size(); i++) {
    S[i] += N;
    if (S[i] > 'Z'){
      S[i] -= 26;
    }
  }
  cout << S << endl;
}

