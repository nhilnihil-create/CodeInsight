#include "bits/stdc++.h"
using namespace std;

int main(void){
    int i = 0;
    string str;
    while (getline(cin, str) && str != ".") {
        stack<char> st;
        bool balanced = true;
        for (char c : str) {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')' || c == ']') {
                if (st.empty()) {
                    balanced = false;
                    break;
                } if (st.top() != '(' && c == ')') {
                    balanced = false;
                    break;
                } else if (st.top() != '[' && c == ']') {
                    balanced = false;
                    break;
                }
                st.pop();
            }
        }
        balanced = balanced && st.empty();
        cout << (balanced ? "yes" : "no") << endl;
    }
}