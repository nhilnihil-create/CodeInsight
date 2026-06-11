#include <bits/stdc++.h>
using namespace std;

int main () {
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  bool check = false;
  int count = 0;
  while (!check){
    if (A >= B) B *=2;
    else if  (B >= C) C *= 2;
    count ++;
    if ((A < B)&&(B < C)) check = true;
  }
  if (K >= count) cout << "Yes" << endl;
  else cout << "No" << endl;
} 