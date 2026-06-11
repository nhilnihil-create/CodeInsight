#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  int n,k,r,s,p;
  string t;
  
  cin >> n >> k >> r >> s >> p >> t;
  vector<int>ans(n);
  for (int i = 0; i < n; i++) {
    if (t.at(i) == 's') ans.at(i) = r;
    else if (t.at(i) == 'p') ans.at(i) = s;
    else ans.at(i) = p;
  }

  for (int i = k; i < n; i++) {
    if (t.at(i-k) == t.at(i)) {
      ans.at(i) = 0;
      t.at(i) = 'a';
    }
  }
  int kotae = 0;
  for (int i = 0; i < n; i++) {
    kotae += ans.at(i);
  }
  cout << kotae << endl;
}