#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define LOOP(i, a, n) for (int i = (int)a; i < (int)n; ++i)
#define REP(i, n) LOOP(i, 0, n)
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265359

int main(void) {
  vector<string> ans;
  while (true) {
    string s;
    getline(cin, s);
    if (s == ".")
      break;
    stack<int> st;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        st.push(1);
      else if (s[i] == '[')
        st.push(2);
      else if (s[i] == ')') {
        if (!st.empty() && st.top() == 1)
          st.pop();
        else {
          flag = false;
          break;
        }
      } else if (s[i] == ']') {
        if (!st.empty() && st.top() == 2)
          st.pop();
        else {
          flag = false;
          break;
        }
      }
      /*
      stack<int> debug;
      debug = st;
      while (!debug.empty()) {
        cout << debug.top() << " ";
        debug.pop();
      }
      cout << endl; */
    }
    if(!st.empty()) flag = false;
    if (flag) {
      ans.push_back("yes");
    } else {
      ans.push_back("no");
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}