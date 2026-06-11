#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  int n,k,q;
  cin >> n >> k >> q;

  vector<int>a(n);
  vector<int>table(q);
  for (int i = 0; i < q; i++) {
    cin >> table.at(i);
    a.at(table.at(i)-1)++;
  }
  for (int i = 0; i < n; i++) {
    int l  = q - a.at(i);
    if (k>l) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}