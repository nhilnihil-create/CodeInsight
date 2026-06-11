#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    while(true) {
        stack<char> cc;
        char c;
        bool success = true;
        string line;
        getline(cin, line);
        if(line == ".") break;
        for(int i = 0; i < line.size(); ++i) {
            c = line[i];
            if(c == '(') cc.push(')');
            if(c == '[') cc.push(']');
            if(c == ')') {
                if(!cc.empty() && cc.top() == ')') cc.pop();
                else success = false;
            }
            if(c == ']') {
                if(!cc.empty() && cc.top() == ']') cc.pop();
                else success = false;
            }
        }
        cout << ((success && cc.empty()) ? "yes" : "no") << endl;
    }
    return 0;
}