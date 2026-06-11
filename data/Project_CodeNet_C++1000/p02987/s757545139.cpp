#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  string s;
  cin >> s;
  vector<char> a;
  rep(i,4){
    a.push_back(s.at(i));
  }
  sort(a.begin(),a.end());
  if(a.at(0) == a.at(1) && a.at(2) == a.at(3) && a.at(0) != a.at(2)) cout << "Yes" << endl;
  else cout << "No" << endl;
  }
