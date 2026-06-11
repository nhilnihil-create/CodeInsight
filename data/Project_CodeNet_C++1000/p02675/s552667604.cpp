/*input
333
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s[] = 
    {"pon", "pon", "hon", 
     "bon", "hon", "hon", 
     "pon", "hon", "pon", 
     "hon"};
  int n;
  cin >> n;
  cout << s[n%10] << endl;
}