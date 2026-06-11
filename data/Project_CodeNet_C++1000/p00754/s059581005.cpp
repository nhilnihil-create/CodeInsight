#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
    map<char,char> close_of;
    close_of['('] = ')';
    close_of['['] = ']';

    while(true) {
        string line;
        getline(cin, line);
        if(line == ".") break;

        bool ok = true;
        stack<char> stk;
        for(int i = 0; i < line.size(); ++i) {
            char c = line[i];
            if(c == '(' || c == '[') {
                stk.push(c);
            }
            else if(c == ')' || c == ']') {
                if(stk.size() == 0 || c != close_of[stk.top()]) {
                    ok = false;
                    break;
                }
                stk.pop();
            }
        }
        if(stk.size() != 0) ok = false;

        cout << (ok?"yes":"no") << endl;
    }

    return 0;
}