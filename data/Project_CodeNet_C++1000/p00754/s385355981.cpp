#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  while (true) {
    string s;
    getline(cin, s);
    if (s == ".") break;
    string ans = "yes";
    std::stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push('(');
      } else if (s[i] == '[') {
        st.push('[');
      } else if (s[i] == ')') {
        if (st.empty() || st.top() != '(') {
          ans = "no";
        }
        if (!st.empty()) st.pop();
      } else if (s[i] == ']') {
        if (st.empty() || st.top() != '[') {
          ans = "no";
        }
        if (!st.empty()) st.pop();
      }
    }
    if (st.size() != 0) ans = "no";

    cout << ans << endl;
  }
}