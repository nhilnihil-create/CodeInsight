#include <bits/stdc++.h>
using namespace std;

int main() {
  int money;
  cin >> money;
  int value;
  value = (money/500)*1000 + 5*(money%500/5);
  cout << value << endl;
}
