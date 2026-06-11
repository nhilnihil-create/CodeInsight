#include <bits/stdc++.h>
using namespace std;

const char a[] = {'(', '['};
const char b[] = {')', ']'};

int main () {
    string str;
    while (getline(cin, str), str.size() > 1) {
        stack<char> s;
        bool ans = true;
        for (int i = 0; i < str.size(); i++) {
            if ('a' > str[i] || str[i] > 'z') {
                if (str[i] == a[0] || str[i] == a[1]) {
                    s.push(str[i]);
                } else if (str[i] == b[0] || str[i] == b[1]) {
                    if (s.empty()) {
                        ans = false; break;
                    } else if (str[i] == b[0] && s.top() == a[0]) {
                        s.pop();
                    } else if (str[i] == b[1] && s.top() == a[1]) {
                        s.pop();
                    } else {
                        ans = false; break;
                    }
                }
            }
        }
        if (s.size() != 0) ans = false;

        cout << (ans ? "yes" : "no") << endl;
    }

    return 0;
}