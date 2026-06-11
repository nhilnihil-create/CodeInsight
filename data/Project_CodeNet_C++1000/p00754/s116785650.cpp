#include <bits/stdc++.h>
using namespace std;

int main() {
   while (1) {
      string s;
      getline(cin, s);
      if (s == ".") break;

      int n = s.size();
      stack<char> stk;
      bool ok = false;
      for (int i = 0; i < n; i++) {
         if (s[i] == '(') stk.push(s[i]);
         if (s[i] == '[') stk.push(s[i]);

         if (s[i] == ')') {
            // )と対応しない
            if (stk.size() == 0 || stk.top() != '(') {
               ok = true;
               break;
            }
            // )と対応する
            stk.pop();
         }
         if (s[i] == ']') {
            // ]と対応しない
            if (stk.size() == 0 || stk.top() != '[') {
               ok = true;
               break;
            }
            // [と対応する
            stk.pop();
         }
      }
      if (!ok && stk.empty()) {
         puts("yes");
      } else {
         puts("no");
      }
   }

   return 0;
}
