#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<string> tenki = {"Sunny", "Cloudy", "Rainy"};
  string S;
  cin >> S;
  for (int i = 0; i < tenki.size(); i++) {
  	if (S == tenki[i]) {
      if (i < tenki.size() - 1) {
      	cout << tenki[i + 1] << endl;
      } else {
      	cout << tenki[0] << endl;
      }
    }
  }
}