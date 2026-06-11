#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main() {
        string s;
        while (getline(cin, s)) {
                if (s == ".") break;
                stack<char> st;
                for (int i = 0; i < s.size(); i ++) {
                        if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']') continue;
                        if (s[i] == '(') {
                                st.push('('); 
                        } else if (s[i] == '[') {
                                st.push('[');
                        } else if (s[i] == ')') {
                                if (st.empty() || st.top() != '(') {
                                        puts("no");
                                        goto end;
                                } else {
                                        st.pop();
                                }
                        } else {
                                if (st.empty() || st.top() != '[') {
                                        puts("no");
                                        goto end;
                                } else {
                                        st.pop();
                                }
                        }
                }
                if (st.empty()) puts("yes");
                else puts("no");
                end:;
        }
        return 0;
}