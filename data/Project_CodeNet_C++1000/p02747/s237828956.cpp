#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main () {
  string S;
  cin >> S;
  if (S.length() % 2 != 0) {
    printf("No\n");
  } else {
    int count = 0;
    for (int i = 0; i < S.length(); i+=2) {
      if (S[i] != 'h' || S[i+1] != 'i') {
        ++count;
        break;
      }
    }
    if (count == 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}