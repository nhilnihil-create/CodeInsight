#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;

int main(void) {
    string s; 
    stack<char> st; 
    char comp;
    bool check;

    while (getline(cin, s)) {
        if (s[0] == '.') {
            break;
        }
        check = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                st.push(s[i]); 
            } else if (s[i] == ')' || s[i] == ']') {
                if (st.empty()) {
                    check = false;
                    break;
                }
                comp = st.top();   
                st.pop();
                if ((comp == '(' && s[i] == ']') || (comp == '[' && s[i] == ')')) {
                    check = false;
                    break;
                }
            }
        }
        if (! st.empty()) {
            check = false;
            while (! st.empty()) {
                st.pop(); 
            }
        }
        if (check == true) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}