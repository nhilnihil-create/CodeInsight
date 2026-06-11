#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)&&s!="."){
        string c;
        for(int i=0;i<s.size();i++)if(s[i]==')'||s[i]=='('||s[i]=='['||s[i]==']')c+=s[i];
        stack<char> s;
        int f=1;
        for(int i=0;i<c.size();i++){
            if(s.empty()||c[i]=='('||c[i]=='[')s.push(c[i]);
            else if((s.top()=='('&&c[i]==')')||(s.top()=='['&&c[i]==']'))s.pop();
            else {f=0;break;}
        }
        if(s.empty())cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}