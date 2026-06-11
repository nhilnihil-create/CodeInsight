#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  string s;

  cin >> s;

  rep(i,s.size()){
    s.at(i) += n;
    if((int)s.at(i)>90){
      s.at(i) -= 26;
    }
  }

  cout << s;

  // cout << (int)'A';
  // cout << endl << (int)'Z';
}
