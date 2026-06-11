#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string a;
  string b;
  cin >> a;
  cin >> b;
  if (a == b.substr(0,a.length())) {
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
