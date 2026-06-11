#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  if (S.back() == 's') S += "e";
  cout << S + 's' << endl;
}
