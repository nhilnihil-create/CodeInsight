#include <iostream>
#include <string>
#include <stack>

using namespace std;

int
main(int argc, const char *argv[])
{
    string str;    
    while (getline(cin, str)) {
        if (str == ".") break;     
        stack<char> sc;
        bool is_balanced = true;
        for (decltype(str.size()) i = 0; i != str.size(); ++i) {
            if (str[i] == '(' || str[i] == '[') sc.push(str[i]);
            else if (str[i] == ')') {
                if (!sc.empty()) {
                    char c = sc.top();
                    sc.pop();
                    if (c != '(') is_balanced = false;
                } else is_balanced = false;
            } else if (str[i] == ']') {
                if (!sc.empty()) {
                    char c = sc.top();
                    sc.pop();
                    if (c != '[') is_balanced = false;
                } else is_balanced = false;
            }
        }
        if (!sc.empty()) is_balanced = false;
        if (is_balanced) cout << "yes";
        else cout << "no";
        cout << endl;
    }

    return 0;
}