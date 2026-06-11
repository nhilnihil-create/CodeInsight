#include<bits/stdc++.h>
using namespace std;

int main() {
  int moji=0;
  string S,T;
  cin >> S >> T;
  for(int i=0;i<S.size();i++) {
    if(S.at(i)==T.at(i)) {
      moji++;
    }
  }
  cout << S.size()-moji << endl;
}