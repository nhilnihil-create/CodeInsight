#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl

int main() {
    while(true) {
        string line; getline(cin, line);
        if(line == ".") break;
        stack<char> s;
        bool valid = true;
        for(int i = 0; i < (int)line.length(); i++) {
            char c = line[i];
            if(c == '(' || c == '[') s.push(c);
            else if(c == ')') {
                if(s.empty() || s.top() != '(') valid = false;
                else s.pop();
            }
            else if(c == ']') {
                if(s.empty() || s.top() != '[') valid = false;
                else s.pop();
            }
        }
        valid &= s.empty();
        cout << (valid ? "yes" : "no") << endl;
    }
}