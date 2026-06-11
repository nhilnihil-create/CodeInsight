#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

#define all(c) (c).begin(), (c).end()

bool solve(string& s){
    s.erase(remove_if(all(s), [](char c){return string("()[]").find(c) == string::npos;}), s.end());
    stack<char> st;
    for(auto c: s){
        if(c == '(' || c == '[')st.push(c);
        else if(st.empty() || st.top() != (c == ')'? '(': '['))return false;
        else st.pop();
    }
    return st.empty();
}

int main(){
    for(string s; getline(cin, s) && s != "."; cout << (solve(s)? "yes\n": "no\n"));
    return 0;
}