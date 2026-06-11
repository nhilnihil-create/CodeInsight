#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    string s;
    while (getline(cin, s)) {
        if (s == ".") break;

        stack<char> paren;
        bool flag = true;
        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                paren.push(s[i]);
            } else if (s[i] == ')') {
                if (!paren.empty()) {
                    char t = paren.top(); paren.pop();
                    if (t != '(') {
                        flag = false;
                    }
                } else {
                    flag = false;
                }
            } else if (s[i] == ']') {
                if (!paren.empty()) {
                    char t = paren.top(); paren.pop();
                    if (t != '[') {
                        flag = false;
                    }
                } else {
                    flag = false;
                }
            }
        }

        if (paren.empty() && flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}