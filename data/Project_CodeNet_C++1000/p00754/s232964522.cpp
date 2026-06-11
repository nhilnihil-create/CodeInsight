#include <iostream>
#include <stack>
#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)

using namespace std;

void solve(string s) {
    bool balance = true;
    stack<char> S;
    for(char& c : s) {
        if(c == '(') S.push('(');
        if(c == '[') S.push('[');
        if(c == ')') {
            if(S.size() == 0) {balance = false; break;}
            if(S.top() == '(') S.pop();
            else balance = false;
        }
        if(c == ']') {
            if(S.size() == 0) {balance = false; break;}
            if(S.top() == '[') S.pop();
            else balance = false;
        }
    }
    if(S.size()) balance = false;
    cout << (balance ? "yes" : "no") << "\n";
}

int main() {
    string s;
    while(getline(cin,s)) {
        if(s[0] == '.') break;
        solve(s);
    }
    return 0;
}