#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if (s.at(0) == s.at(1) && s.at(2) == s.at(3) && s.at(1) != s.at(2)) {
    cout << "Yes" << endl;
  } else cout << "No" << endl;
}
