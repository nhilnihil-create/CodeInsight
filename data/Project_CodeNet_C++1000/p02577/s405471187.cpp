#include <bits/stdc++.h>
using namespace std;
int main(){
  string n;
  cin >> n;
  int nm{};
  for(int i=0; i<n.size(); i++){
    nm = (nm + (n[i] - '0')) % 9;
  }
  cout << (nm == 0 ? "Yes" : "No") << endl;
}