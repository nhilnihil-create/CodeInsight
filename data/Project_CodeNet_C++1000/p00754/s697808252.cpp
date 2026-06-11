#include<bits/stdc++.h>
using namespace std;

string str;

void solve(){
    stack<int>S;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(')S.push(1);
        else if(str[i]=='[')S.push(0);
        else if(str[i]==')'){
            if(S.empty()||S.top()!=1){
                cout<<"no"<<endl;
                return;
            }
            S.pop();
        }
        else if(str[i]==']'){
            if(S.empty()||S.top()!=0){
                cout<<"no"<<endl;
                return;
            }
            S.pop();
        }
    }
    if(S.empty())cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
int main(){
    while(getline(cin,str),str!=".")solve();
    return 0;
}