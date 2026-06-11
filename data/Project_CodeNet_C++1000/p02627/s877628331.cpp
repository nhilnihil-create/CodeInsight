#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  char a;
  cin >> a;

  if(isupper(a)) {
    cout << "A" << endl;
  }

  else if(islower(a)) {
    cout << "a" << endl;
  }
  return 0;
}
