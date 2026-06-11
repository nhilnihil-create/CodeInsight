#include <bits/stdc++.h>
using namespace std;

int main() { 
  int N;
  string S;
  cin >> N >> S;
  string ans="Yes";
  if (S.size()%2==1) {
    ans="No";
  }
  for (int i=0; i<S.size()/2; i++) {
    if (S.at(i)!=S.at(i+S.size()/2)) {
      ans ="No";
      break;
    }
  }
  cout << ans << endl;
} 