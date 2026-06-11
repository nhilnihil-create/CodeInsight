#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    while(getline(cin,str),str!=".") {
        stack<char> st;
        bool OK=1;
        for(int i=0;i<str.size();i++) {
            if(str[i]=='(') st.push('(');
            if(str[i]==')') {
                if(st.size()==0||st.top()!='(') {OK=0;break;}
                st.pop();
            }
            if(str[i]=='[') st.push('[');
            if(str[i]==']') {
                if(st.size()==0||st.top()!='[') {OK=0;break;}
                st.pop();
            }
        }
        if(st.size()==0&&OK) printf("yes\n"); else printf("no\n");
    }
}