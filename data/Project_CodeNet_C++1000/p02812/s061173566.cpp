#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main() {
  int n;

  string s;

  cin >> n >> s;

  int flag = 0;

  for(int i = 0; i<=n-3; i++){
    if(s.at(i) == 'A' && s.at(i+1) == 'B' && s.at(i+2) == 'C')
    flag++;
  }

  cout << flag;
}