#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  int size = s.size();

  for (int i = 0; i < size/2; i++) {
    if (s[i] != s[size-(i+1)]) {
      cout << "No" << endl;
      return 0;
    }
  }

  int condition_2 = ((size-1)/2);
  for (int i = 0; i < condition_2/2; i++) {
    if (s[i] != s[condition_2-(i+1)]) {
      cout << "No" << endl;
      return 0;
    }
  }

  for (int i = ((size+3)/2)-1; i < size; i++) {
    if (s[i] != s[size-(i+1)]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}