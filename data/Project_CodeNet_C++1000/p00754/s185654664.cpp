#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string str;
vector< int > stk;

int main() {
  while (getline(cin, str) && str != ".") {
    stk.clear();
    bool is_valid = true;
    int ln = str.length();
    for (int i = 0; i < ln && is_valid; ++i) {
      if (str[i] == '(')
        stk.push_back('(');
      if (str[i] == '[')
        stk.push_back('[');
      if (str[i] == ')') {
        if (stk.size() == 0 || stk.back() != '(')
          is_valid = false;
        else
          stk.pop_back();
      }
      if (str[i] == ']') {
        if (stk.size() == 0 || stk.back() != '[')
          is_valid = false;
        else
          stk.pop_back();
      }
    }
    if (stk.size() > 0) is_valid = false;

    cout << (is_valid ? "yes" : "no") << "\n";
  }

  return 0;
}