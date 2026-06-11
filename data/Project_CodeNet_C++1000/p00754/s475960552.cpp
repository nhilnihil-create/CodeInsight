#include <bits/stdc++.h>
using namespace std;
int main(void){
    string str,ans=")]";
    while(getline(cin,str)&&str!="."){
        stack<int> sta;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(')sta.push(0);
            if(str[i]=='[')sta.push(1);
            if((str[i]==')'||str[i]==']')&&!sta.empty()&&str[i]==ans[sta.top()])sta.pop();
            else if(str[i]==')'||str[i]==']'){
                sta.push(0);
                break;
            }
        }
        if(sta.empty())cout<<"yes\n";
        else cout<<"no\n";
    }
}