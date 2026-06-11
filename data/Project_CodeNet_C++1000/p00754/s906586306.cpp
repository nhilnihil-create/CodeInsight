#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int main(){
    map<char,int>M;
    M['(']=M[')']=1;
    M['[']=M[']']=2;
    string str;
    while(getline(cin,str),str!="."){
        bool flag=true;
        stack<int>S;
        for(int i=0;i<str.length();i++){
            char c=str[i];
            if(c=='('||c=='['){
                S.push(M[c]);
            }
            if(c==')'||c==']'){
                if(S.size()==0){
                    flag=false;
                    break;
               }
                if(S.top()!=M[c]){
                    flag=false;
                    break;
                }
                S.pop();
            }
        }
        if(S.size())flag=false;
        puts(flag?"yes":"no");
    }
    return 0;
}