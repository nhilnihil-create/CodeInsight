#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int main() {
    string s;
    while(1){
        getline(cin, s);
        if(s == ".") break;
        stack<char> st;
        bool f = true;
        rep(i, 0, s.size()){
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(st.empty()){
                    f = false;
                    continue;
                }
                if(st.top() != '(') f = false;
                st.pop();
            }else if(s[i] == ']'){
                if(st.empty()){
                    f = false;
                    continue;
                }
                if(st.top() != '[') f = false;
                st.pop();
            }
        }
        if(!st.empty()) f = false;
        if(f) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
