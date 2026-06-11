#include <iostream>
#include <string>
#include <stack>

using namespace std;

namespace Solver {

    string s;
    inline bool Read() {
        getline(cin, s);
        return s != ".";
    }

    inline void Work() {
        stack<char> stk;
        bool ok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                stk.push(s[i]);
            } else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[') {
                    ok = false;
                } else {
                    stk.pop();
                }
            } else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(') {
                    ok = false;
                } else {
                    stk.pop();
                }
            }
        }

        if (stk.empty() && ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    inline void Solve() {
         while(Read()) Work();
    }
}

int main() {
    Solver::Solve();
}