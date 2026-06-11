#include <bits/stdc++.h>
using namespace std;

int main () {
    string str;
    map<char,char> c;
    c[']'] = '[';
    c[')'] = '(';
    while (getline(cin,str), str != ".") {
        stack<char> s;
        bool flag = true;
        for (int i = 0; flag && i < str.size(); i++) {
            if (string("[()]").find(str[i]) == string::npos) continue;
            if (string("[(").find(str[i]) != string::npos) {
                s.push(str[i]);
            }
            else if (string("])").find(str[i] != string::npos)) {
                if (s.size() == 0) flag = false;
                else if (c.find(str[i]) != c.end() && c[str[i]] == s.top()) s.pop();
                else if (c.find(str[i]) != c.end() && c[str[i]] == s.top()) s.pop();
                else flag = false;
            }
        }

        cout << (flag && !s.size() ? "yes" : "no") << endl;
    }
}