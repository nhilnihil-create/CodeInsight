#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin, s) , s != ".") {
        stack<char> v;
        bool flag = true;
        for (int i = 0; i < s.size() && flag; i++) {
            if (s[i] == '(' || s[i] == '[') v.push(s[i]);
            else if (s[i] == ')' && v.size() && v.top() == '(') v.pop();
            else if (s[i] == ']' && v.size() &&  v.top() == '[') v.pop();
            else if (s[i] == ')' || s[i] == ']') flag = false;
        }

        if (flag && v.size() == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}

