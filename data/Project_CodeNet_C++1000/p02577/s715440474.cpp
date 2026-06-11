#include<bits/stdc++.h>
using namespace std;

int main() {
  int kari;
  int gokei=0;
  string kazu;
  cin >> kazu;
  for(int i=0;i<kazu.size();i++) {
    gokei+=kazu.at(i)-'0';
  }
  if(gokei%9==0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}