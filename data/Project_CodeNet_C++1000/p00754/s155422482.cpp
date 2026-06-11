#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for(int i=0; i<(n); ++i)

int main(void){
    string s;
    char bra[] = {'(', ')', '[', ']'};
    while(getline(cin, s) && s!=".") {
        stack<char> stk;
        bool ok = true;
        rep(i, s.size()) {
            bool is_bracket = false;
            rep(j, 4) if(s[i] == bra[j]) is_bracket = true;
            if(!is_bracket) continue;
            if(stk.empty() || s[i] == '(' || s[i] == '[') stk.push(s[i]);
            else if( (stk.top() == '(' && s[i] == ')') ||
                     (stk.top() == '[' && s[i] == ']') ) stk.pop();
            else {
                ok = false;
                break;
            }
        }

        if(ok && stk.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}