#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.size();
  int ans = 0;
  bool judge = true;
  
  for(int i=0; i<N; i +=2) {
    if(s.at(i) =='L') {
      judge = false;
      break;
    }
    for(int j=1; j<N; j +=2) {
      if(s.at(j) =='R') {
        judge = false;
        break;
      }
    }
  }
  if(judge == true) cout << "Yes" << endl;
  if(judge == false) cout << "No" << endl;
}