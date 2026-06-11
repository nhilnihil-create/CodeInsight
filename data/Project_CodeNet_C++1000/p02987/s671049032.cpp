#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  vector<char> a(4);
  rep(i,4){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  if(a.at(0) == a.at(1) && a.at(2) == a.at(3) && a.at(0) != a.at(2)) cout << "Yes" << endl;
  else cout << "No" << endl;
  }
