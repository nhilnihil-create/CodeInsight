#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  string s;
  cin >> s;
  vector<string> days = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

  rep(i,7){
  if(s == days.at(i)) cout << 7 -i << endl;

}  
  }

