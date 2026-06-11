#include <iostream>
#include <string>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  string s, sr, a, ar;
  cin >> s;
  sr = s;
  reverse(sr.begin(), sr.end());
  int q;
  cin >> q;
  rep(i,q) {
    int t;
    cin >> t;
    if(t == 1) {
      swap(s, sr);
      swap(a, ar);
    } else {
      int f; char c;
      cin >> f >> c;
      if(f == 1) a = a + c;
      else ar = ar + c;
    }
  }
  reverse(a.begin(), a.end());
  cout << a + s + ar << endl;
  return 0;
}