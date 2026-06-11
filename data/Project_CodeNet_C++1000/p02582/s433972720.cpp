#include<bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ame=0;
  for(int i=0;i<3;i++) {
    if(S.at(i)=='R') {
      if(i<=1) {
        if(S.at(i+1)=='R') {
          if(i==0) {
            if(S.at(i+2)=='R') {
              ame=3;
              break;
            } else {
              ame=2;
              break;
            }
          } else {
            ame=2;
            break;
          }
        } else {
          ame=1;
          break;
        }
      } else {
        ame=1;
        break;
      }
    }
  }
  cout << ame << endl;
}