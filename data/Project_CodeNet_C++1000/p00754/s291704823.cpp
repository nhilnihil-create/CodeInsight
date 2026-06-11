#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    while(getline(cin,s),s!="."){
        stack<int> b;
        bool isBn=true;
        for(auto c : s){
            if(c=='(') b.push(1);
            if(c=='[') b.push(2);
            if(c==')'){
                if(!b.empty() && b.top()==1){
                    b.pop();
                }else{
                    isBn=false;
                    break;
                }
            }
            if(c==']'){
                if(!b.empty() && b.top()==2){
                    b.pop();
                }else{
                    isBn=false;
                    break;
                }
            }
        }
        if(isBn==false || !b.empty()){
            cout<<"no"<<endl;
        }else{
            cout<<"yes"<<endl;
        }
    }
}