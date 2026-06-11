#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  string cStr; cin >> cStr;
  
  int wNumber = 0, rNumber = 0, alreadyPlaced = 0;
  
  for (int i = 0; i < cStr.size(); i++) {
    if (cStr.at(i) == 'W') wNumber++;
    if (cStr.at(i) == 'R') rNumber++;
  }
  
  for (int i = 0; i < rNumber; i++) {
    if (cStr.at(i) == 'R') alreadyPlaced++;
  }
  
  int ans = min(rNumber - alreadyPlaced, wNumber);
  
  cout << ans << endl;
  
}