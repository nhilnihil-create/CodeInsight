#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) REP((i), 0, (n))
#define REP(i, a, n) for(int i=(a); i<(n); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1) {
        string s; getline(cin, s);
        if(s == ".") break;

        stack<char> st;
        bool flag = true;
        for(char c : s) {
            if(c == '(' || c == '[') {
                st.push((c=='('? ')':']'));
            } else if(c == ')' || c == ']') {
                if(st.empty() || st.top() != c) {
                    flag = false;
                    break;
                }
                st.pop();
            }
        }
        flag = flag? st.empty():flag;
        cout << (flag? "yes":"no") << endl;
    }
}
