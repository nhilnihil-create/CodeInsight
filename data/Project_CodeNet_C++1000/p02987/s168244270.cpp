#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  map<char, int> m;
  for (char c : S) m[c]++;
  if (m.size() != 2) cout << "No" << endl;
  else if (m.begin()->second != 2) cout << "No" << endl;
  else cout << "Yes" << endl;
}
