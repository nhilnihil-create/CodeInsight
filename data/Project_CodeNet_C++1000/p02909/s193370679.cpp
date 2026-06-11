#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  if (S == "Sunny") cout << "Cloudy" << endl;
  if (S == "Cloudy") cout << "Rainy" << endl;
  if (S == "Rainy") cout << "Sunny" << endl;
  return 0;
}