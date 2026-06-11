#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int main(){
    string s;
    while(1){
        getline(cin, s);
        if(s == ".") break;
        stack<char> st;
        bool f = true;
        rep(i, 0, s.size()){
            // cout << s[i] << endl;
            if(s[i] == '(') st.push(s[i]);
            if(s[i] == '[') st.push(s[i]);
            if(s[i] == ')'){
                if(st.empty()){
                    f = false;
                    break;
                }
                char c = st.top(); st.pop();
                if(c != '(') f = false;
            }
            if(s[i] == ']'){
                if(st.empty()){
                    f = false;
                    break;
                }
                char c = st.top(); st.pop();
                if(c != '[') f = false;
            }
        }
        // cout << 1 << endl;
        if(!st.empty()) f = false;
        cout << (f ? "yes" : "no") << endl;
    }
}