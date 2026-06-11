#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string input;
    while (true) {
        stack<char> parenthesis;
        getline(cin, input);
        if (input == ".") {
            break;
        }
        bool is_valid = true;
        for (int i=0; i<(int)input.length(); i++) {
            if (input[i] == '(' || input[i] == '[') {
                parenthesis.push(input[i]);
            }
            else if (input[i] == ')') {
                if (parenthesis.size() > 0 && parenthesis.top() == '(') {
                    parenthesis.pop();
                }
                else {
                    is_valid = false;
                    break;
                }
            }
            else if (input[i] == ']') {
                if (parenthesis.size() > 0 && parenthesis.top() == '[') {
                    parenthesis.pop();
                }
                else {
                    is_valid = false;
                    break;
                }
            }
        }
        if (parenthesis.size() > 0) {
            is_valid = false;
        }
        if (is_valid) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}