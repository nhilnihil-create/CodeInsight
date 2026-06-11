#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  bool good = true;

  cin >> S;

  for (int i = 0; i < S.size(); i++){
    if ((i + 1) % 2 == 0 && S.at(i) == 'R') good = false;
    else if ((i + 1) % 2 != 0 && S.at(i) == 'L') good = false;     
  }

  cout << (good ? "Yes" : "No") << endl;
}