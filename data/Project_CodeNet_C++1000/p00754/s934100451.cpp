#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
    while(getline(cin,str)){
        if(str==".") break;
        stack<char> stk;
        string res = "yes";
        for(int i=0;i<str.size();i++){
            if(str[i]=='(') stk.push('(');
            if(str[i]=='[') stk.push('[');
 
            if(str[i]==')'){
                if(!stk.empty() && stk.top() != '(') res = "no";
                else if(stk.empty()) res = "no";
                else stk.pop();
            }
 
            if(str[i]==']'){
                if(!stk.empty() && stk.top() != '[') res = "no";
                else if(stk.empty()) res = "no";
                else stk.pop();
            }
 
        }
 
        if(!stk.empty()) res = "no";
        cout << res << endl;
    }
}