#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char *argv[])
{
    string line, res;
    while (getline(cin, line), line != ".") {
        stack<char> st;
        res = "yes";
        for (int i = 0; i < line.size(); ++i) {
            char tmp = line[i];
            if (tmp == '(' || tmp == '[') {
                st.push(tmp);
            } else if (tmp == ')') {
                if (st.empty() || st.top() != '(') {
                    res = "no";
                    break;
                }
                st.pop();
            } else if (tmp == ']') {
                if (st.empty() || st.top() != '[') {
                    res = "no";
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
            res = "no";
        cout << res << endl;
    }
    return 0;
}