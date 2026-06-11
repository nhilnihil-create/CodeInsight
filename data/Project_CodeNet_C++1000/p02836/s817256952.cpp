#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int sum = 0;
  for(int i = 0; i < N / 2; i++) {
    if(S.at(i) != S.at(N-i-1)) sum++;
  } 
  cout << sum << endl;
}