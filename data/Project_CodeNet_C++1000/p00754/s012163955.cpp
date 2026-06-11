#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

#define el endl
#define fd fixed
#define INF INT_MAX/2-1
#define pb push_back

using namespace std;

int main() {
  string s;
  bool flag;
  while (getline(cin, s), s != ".") {
    flag = true;
    stack<char> kakko;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '[') {
        kakko.push(s[i]);
      }
      if (s[i] == ')') {
        if (kakko.empty() || kakko.top() != '(') {
          flag = false;
          break;
        }
        kakko.pop();
      }
      if (s[i] == ']') {
        if (kakko.empty() || kakko.top() != '[') {
          flag = false;
          break;
        }
        kakko.pop();
      }
    }
    if (!kakko.empty()) flag = false;
    if (flag) cout << "yes" << el;
    else cout << "no" << el;
  }
}