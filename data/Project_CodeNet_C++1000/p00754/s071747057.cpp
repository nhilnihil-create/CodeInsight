#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

main() {
string str;
while(getline(cin, str), str!="."){
    string tmp = "";
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
            tmp += str[i];
    }
    bool f = 1;
    stack<char> stk;
    for(int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == '(' || tmp[i] == '[')
            stk.push(tmp[i]);
        else if (!stk.empty()){
            char top = stk.top();
            stk.pop();
            if (tmp[i] == ')' && top == '(') {

            } else if (tmp[i] == ']' && top == '['){
            } else {
                f = 0;
            }
        } else {
        f = 0;
        }
    }
    if (!stk.empty()) f = 0;
    cout << (f ? "yes" : "no") << endl;
}
}