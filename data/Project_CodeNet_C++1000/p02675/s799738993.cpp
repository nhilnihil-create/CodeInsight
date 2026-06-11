#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string n;
  cin >> n;
  int t = (int)n.size() - 1;
  if(n.at(t) == '0' || n.at(t) == '1' || n.at(t) == '6' || n.at(t) == '8') {
    cout << "pon" << endl;
    return 0;
  }
  else if(n.at(t) == '3') {
    cout << "bon" << endl;
    return 0;
  }
  else {
    cout << "hon" << endl;
    return 0;
  }
}