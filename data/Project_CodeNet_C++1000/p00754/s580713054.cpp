#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str;
    while(true){
        getline(cin,str);
        if(str==".") return 0;
        bool ok = true;
        stack<char> s;
        for(auto c:str){
            if(c=='('||c=='['){
                s.push(c);
            }else if(c==']'){
                if(s.size()&&s.top()=='[') s.pop();
                else{
                    ok=false;
                    break;
                }
            }else if(c==')'){
                if(s.size()&&s.top()=='(') s.pop();
                else{
                    ok=false;
                    break;
                }
            }
        }
        if(ok&&!s.size()){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}