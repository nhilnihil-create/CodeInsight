#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  string s;
  cin >> s;
  while (s.size() >= 2 && s.substr(0,2) == "hi") s.erase(s.begin(), s.begin()+2);

  if (s.empty()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


}
