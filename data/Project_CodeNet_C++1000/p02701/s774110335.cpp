#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  map<string, int> a;
  rep(i, n) {
    string s;
    cin >> s;
    a[s] = 1;
  }

  cout << a.size();
}
