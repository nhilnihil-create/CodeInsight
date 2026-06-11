#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool flag = true;

  if (S.size() % 2 != 0) {
    cout << "No";
    return 0;
  }

  for (int i = 0; i < S.size(); i+=2){
    if (S.at(i) != 'h' || S.at(i + 1) != 'i') flag = false;
  }
  if (flag) cout << "Yes";
  else cout << "No";
}