#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string s; cin >> s;
  map<string, string> m = {{"Sunny", "Cloudy"}, {"Cloudy", "Rainy"}, {"Rainy", "Sunny"}};
  cout << m[s] << endl;
}
