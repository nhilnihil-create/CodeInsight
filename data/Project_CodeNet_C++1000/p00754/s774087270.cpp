#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    string s;

    while (1) {
        bool flag = false;
        getline(cin, s);
        if (s == ".") break;

        stack<char> sc;
        char tmp;
        for (auto i : s) {
            switch (i) {
            case '(':
                sc.push('(');
                break;
            case '[':
                sc.push('[');
                break;
            case ')':
                if (sc.size() == 0) {
                    flag = true;
                    break;
                }

                tmp = sc.top();
                if (tmp == '(') {
                    sc.pop();
                } else {
                    flag = true;
                }
                break;
            case ']':
                if (sc.size() == 0) {
                    flag = true;
                    break;
                }

                tmp = sc.top();
                if (tmp == '[') {
                    sc.pop();
                } else {
                    flag = true;
                }
                break;
            }
            if (flag) break;
        }
        if (flag || sc.size() != 0) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
    return 0;
}