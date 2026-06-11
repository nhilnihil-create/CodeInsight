#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  string n;
  cin >> n;
  rep(i, 3) {
    if(n[i] == '7') {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
