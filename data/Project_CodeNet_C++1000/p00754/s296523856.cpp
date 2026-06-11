#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    while(1) {
        string s;
        getline(cin, s);

        if (s == ".") break;
        string b = "";
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(' || c == ')' || c == '[' || c == ']') {
                b.push_back(c);
            }
        }
        
        stack<char> stack;
        bool ok = true;
        //cout << b << endl;
        for (int i = 0; i < b.size(); ++i) {
            switch(b[i]) {
                case '(':
                case '[':
                    stack.push(b[i]);
                break;
                case ')':
                    if (stack.empty()) {ok = false; break;}
                    if (stack.top() == '(') stack.pop();
                    else ok = false;
                break;
                case ']':
                    if (stack.empty()) {ok = false; break;}
                    if (stack.top() == '[') stack.pop();
                    else ok = false;
                break;
            }

            if (!ok) break;
            //cout << stack.size() << endl;
        }

        ok = ok && (stack.size() == 0);

        cout << (ok ? "yes" : "no") << endl;
    }
}