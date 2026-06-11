#include <bits/stdc++.h>
using namespace std;

int main () {
  vector<string> weth={"Sunny","Cloudy","Rainy","Sunny"};
  string s;
  cin >> s;

  for (int i=0;i<3;++i) {
    if (s==weth[i]) {
      cout << weth[i+1] << endl;
      break;
    }
  }

  return 0;
}
