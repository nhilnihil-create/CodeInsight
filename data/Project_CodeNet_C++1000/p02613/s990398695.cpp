#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, ac = 0, wa = 0, tle = 0, re = 0;
  cin >> N;
  string s;
  
  rep(i,N) {
    cin >> s;    
    if (s == "AC") {
      ac++;
    }
    if (s == "WA") {
      wa++;
    }
    if (s == "TLE") {
      tle++;
    }
    if (s == "RE") {
      re++;
    }
  }
  
  cout << "AC x " << ac << endl;
  cout << "WA x " << wa << endl;
  cout << "TLE x " << tle << endl;
  cout << "RE x " << re << endl; 
}