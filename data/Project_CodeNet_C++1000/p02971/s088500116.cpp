#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const float pi = 3.1415926535;
unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>a_copy(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    a_copy.at(i) = a.at(i);
  }
  sort(a_copy.begin(),a_copy.end());
  reverse(a_copy.begin(),a_copy.end());
  
  for (int i = 0; i < n; i++) {
    if (a.at(i) == a_copy.at(0)) cout << a_copy.at(1) << endl;
    else cout << a_copy.at(0) << endl;
  }
}