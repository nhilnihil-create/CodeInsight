 #include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
 
  rep(i, s.size()) {
    int x = s.at(i) - 'A';
    x = (x + n) % 26;
    cout << (char)('A' + x);
  }
  cout << endl;
  return 0;
}
      