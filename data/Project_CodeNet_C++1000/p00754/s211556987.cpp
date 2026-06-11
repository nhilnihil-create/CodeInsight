#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    stack<char> stk;
    for(char c:s){
        if(c=='('){
            stk.push('(');
        }
        if(c=='['){
            stk.push('[');
        }
        if(c==')'){
            if(!stk.empty()&&stk.top()=='(')stk.pop();
            else {cout<<"no"<<endl;return;}
        }
        if(c==']'){
            if(!stk.empty()&&stk.top()=='[')stk.pop();
            else {cout<<"no"<<endl;return;}
        }
    }
    if(!stk.empty())cout<<"no"<<endl;
    else cout<<"yes"<<endl;
}

int main (){
    string s;
    while(getline(cin,s),s[0]!='.'&&s.size()!=1){
        solve(s);
    }
}