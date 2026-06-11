#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    for (;;) {
        string str;
        getline(cin, str);
        if (str == ".")
            break;

        stack<int> s;
        string::iterator i;
        for (i = str.begin(); i != str.end(); ++i) {
            if (*i == '(') {
                s.push(1);
            } else if (*i == ')') {
                if (!s.empty() && s.top() == 1)
                    s.pop();
                else
                    break;
            } else if (*i == '[') {
                s.push(2);
            } else if (*i == ']') {
                if (!s.empty() && s.top() == 2)
                    s.pop();
                else
                    break;
            }
        }
        if (i == str.end() && s.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}